#include <Canvas.hpp>

Canvas::Canvas(): vbo(Canvas_VertexData), ibo(Canvas_IndexData) {
    std::cout << "Generating canvas ...\n";
    VertexBufferLayout buffer_layout;;

    buffer_layout.Push<GLfloat>(3);
    buffer_layout.Push<GLfloat>(2);
    vao.AddBuffer(GetVertexBuffer(), buffer_layout);
}

Canvas::~Canvas() {
    std::cout << "Deleting canvas ... \n";
}

void Canvas::Bind() const {
    vao.Bind();
    ibo.Bind();
    sp.Bind();
}

void Canvas::Release() const {
    vao.Release();
    ibo.Release();
    sp.Release();
}

const VertexBuffer &Canvas::GetVertexBuffer() const {
    return vbo;
}

const IndexBuffer &Canvas::GetIndexBuffer() const {
    return ibo;
}

const ShaderProgram &Canvas::GetShaderProgram() const {
    return sp;
}
