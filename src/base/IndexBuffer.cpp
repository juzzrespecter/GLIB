#include <IndexBuffer.hpp>

IndexBuffer::IndexBuffer(const std::vector< int> &i,
    unsigned int size,
    GLuint mode)
{
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id));
    GL_wrap(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, i.data(), mode));
    GL_wrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(const std::vector< int> &i, unsigned int size)
{
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id));
    GL_wrap(glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, i.data(), GL_STATIC_DRAW));
    GL_wrap(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(const IndexBuffer & o)
{

}

IndexBuffer::~IndexBuffer()
{
    GL_wrap(glDeleteBuffers(1, buffer_id));
}

GLuint IndexBuffer::GetId() const
{
    return (buffer_id);
}

void IndexBuffer::Bind(void) const
{
glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_id);
}

void IndexBuffer::Release(void) const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
