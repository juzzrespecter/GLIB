#include <VertexBuffer.hpp>

VertexBuffer::VertexBuffer(const std::vector<float>& vb,
                           unsigned int size,
                           GLuint mode): v_positions(vb)
{
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
    GL_wrap(glBufferData(GL_ARRAY_BUFFER, size, vb.data(), mode));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::VertexBuffer(const std::vector<float>& vb, unsigned int size): v_positions(vb)
{
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
    GL_wrap(glBufferData(GL_ARRAY_BUFFER,
        size,
        vb.data(),
        GL_STATIC_DRAW));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

VertexBuffer::VertexBuffer(const VertexBuffer& o): v_positions(o.v_positions)
{
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
}

VertexBuffer::~VertexBuffer()
{
glDeleteBuffers(1, &buffer_id);
}

GLuint VertexBuffer::GetId(void) const
{
   return (buffer_id);
}

void VertexBuffer::Bind() const
{
glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
}

void VertexBuffer::Release(void) const
{
glBindBuffer(GL_ARRAY_BUFFER, 0);
}