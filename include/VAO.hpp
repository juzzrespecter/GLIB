#ifndef VAO_HPP
# define VAO_HPP

#include <cassert>
# include <glib_internals.hpp>
#include <VertexBuffer.hpp>

// probablemente algo para los atributos

/**
 * Estructura que almacena la configuracion asociada a un VertexBuffer.
 * @type: tipo de variable del elemento
 * @size: numero de variables que forman el elemento {1, 2, 3 o 4}
 * @normalized: indica si los parametros estan normalizados o no
 */
struct VertexBufferElement {
  GLenum type;
  GLint size;
  GLboolean normalized;

  static unsigned int GetSize(GLenum type) {
    switch (type) {
      case GL_INT: return 4;
      case GL_UNSIGNED_INT: return 4;
      case GL_FLOAT: return 4;
      default: {
        assert(false);
        return 0;
      };
    }
  }
};


/**
 * Clase que abstrae el layout a aplicar sobre un VAO.
 * @elements: Lista de informacion sobre los atributos a aplicar.
 * @stride: Tamanyo del vertex definido en el layout.
 */
class VertexBufferLayout {
private:
  typedef std::vector<VertexBufferElement> GL_vector_element;

  GL_vector_element elements;
  GLuint stride;

public:
  VertexBufferLayout();

  VertexBufferLayout(const VertexBufferLayout &o) = default;

  ~VertexBufferLayout();

  template<typename T>
  void Push(GLint size) {
    (void) size;

    assert(false);
  }

  GLuint GetStride() const;

  const GL_vector_element &GetElements() const;
};




/**
* Clase de cobertura de un Vertex Array Object o VAO,
* encapsula un Vertex Buffer con una configuración o layout para poder accionar
* con glVertexAttribPointer.
*
* @vao_id: identificador interno de OpenGL para la instancia creada de VAO.
*/

class VAO {
private:
  GLuint vao_id;

public:
  VAO();

  ~VAO();

  void Bind() const;

  void Release() const;

  GLuint GetId() const;

  void AddBuffer(const VertexBuffer &, const VertexBufferLayout &) const;
};

#endif // VAO_HPP
