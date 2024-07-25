#ifndef VAO_HPP
# define VAO_HPP

# include <glib_internals.hpp>
/**
* Clase de cobertura de un Vertex Array Object o VAO,
* encapsula un Vertex Buffer con una configuración o layout para poder accionar
* con glVertexAttribPointer.
*/

class VAO {
private:
  GLuint vao_id;

public:
  VAO();
  ~VAO();

  void Bind() const;
  void Release() const;
};

#endif // VAO_HPP