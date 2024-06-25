#include <Canvas.hpp>

Canvas::Canvas(void): _canvas_id(0) { }
Canvas::Canvas(GLuint id): _canvas_id(id) { }
Canvas::~Canvas() {}

void    Canvas::Init_canvas(const std::vector<float>& buffer, GLuint size)
{
    GL_wrap(glGenBuffers(1, &_canvas_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, _canvas_id));
    GL_wrap(glBufferData(GL_ARRAY_BUFFER, size, buffer.data(), GL_STATIC_DRAW));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

GLuint  Canvas::get_id(void) const
{
    return _canvas_id;
}

void    Canvas::set_id(GLuint id)
{
    _canvas_id = id;
}

void    Canvas::Bind(void) const
{
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, _canvas_id));
}

void    Canvas::Release(void) const
{
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

// set buffer

// bind

// unbind