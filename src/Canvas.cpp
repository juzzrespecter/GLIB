#include <Canvas.hpp>

Canvas::Canvas(void): _canvas_id(0) { }
Canvas::Canvas(GLuint id): _canvas_id(id) { }
Canvas::~Canvas() {}

GLuint  Canvas::get_id(void) const
{
    return _canvas_id;
}