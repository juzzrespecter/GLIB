#include <VertexBuffer.hpp>

VertexBuffer::VertexBuffer(const std::vector<float> &vb, GLuint mode): v_positions(vb) {
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vb.size(), vb.data(), mode);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(const std::vector<float> &vb): buffer_id(0), v_positions(vb) {
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER,
        sizeof(float) * vb.size(),
        vb.data(),
        GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::VertexBuffer(const VertexBuffer &o): v_positions(o.v_positions) {
    glGenBuffers(1, &buffer_id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &buffer_id);
}

GLuint VertexBuffer::GetId() const {
    return (buffer_id);
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void VertexBuffer::Release() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
