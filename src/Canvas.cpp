#include <Canvas.hpp>

Canvas::Canvas(void) {

}

Canvas::~Canvas() {

}

void    Canvas::Init_canvas(const std::vector<float>& buffer, GLuint size)
{
    /* iniciamos el vertex buffer, el index buffer y el shader program */
    vbo = new VertexBuffer(buffer);
    GL_wrap(glGenBuffers(1, &_canvas_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, _canvas_id));
    GL_wrap(glBufferData(GL_ARRAY_BUFFER, size, buffer.data(), GL_STATIC_DRAW));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}