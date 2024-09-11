#ifndef VAO_HPP
# define VAO_HPP

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
        static_assert(false);
        return 0;
      };
    }
  }
};


/**
 * Clase que abstrae el layout a aplicar sobre un VAO.
 * @elements:
 * @stride:
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

  template<
    typename Int,
    typename std::enable_if<std::is_integral_v<Int> && std::is_signed_v<Int>>::type* = nullptr
  >
  void Push(Int size) {
    elements.push_back({GL_INT, size, GL_FALSE});
    stride += VertexBufferElement::GetSize(GL_INT);
  }

  template<
    typename UInt,
    typename std::enable_if<std::is_integral_v<UInt> && !std::is_signed_v<UInt>>::type* = nullptr
  >
  void Push(UInt size) {
    elements.push_back({GL_UNSIGNED_INT, size, GL_FALSE});
    stride +=  VertexBufferElement::GetSize(GL_UNSIGNED_INT);
  }

  template<
    typename Float,
    typename std::enable_if<std::is_floating_point_v<Float> >::type* = nullptr
  >
  void Push(Float size) {
    elements.push_back({GL_FLOAT, size, GL_FALSE});
    stride += VertexBufferElement::GetSize(GL_FLOAT);
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
* @stride:
* @
*/

class VAO {
private:
  GLuint vao_id;
  GLuint stride;

  std::vector<VertexBufferLayout> layouts;

public:
  VAO();

  ~VAO();

  void Bind(const VertexBuffer&, const VertexBufferLayout&) const;

  void Release() const;

  GLuint GetId() const;

  void AddBuffer(const VertexBuffer &, const VertexBufferLayout &);
};

#endif // VAO_HPP
