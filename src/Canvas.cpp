#include <Canvas.hpp>

Canvas::Canvas(const std::vector<float>& vb, unsigned int vb_size,
       const std::vector<unsigned int>& ib, unsigned int ib_size)
       : vbo(vb, vb_size), ibo(ib, ib_size), sp() {

}

Canvas::~Canvas() {

}

void Canvas::Bind(void) const {
    vbo.Bind();
    ibo.Bind();
    sp.Bind();
}

void Canvas::Release(void) const {
    vbo.Release();
    ibo.Release();
    sp.Release();
}
