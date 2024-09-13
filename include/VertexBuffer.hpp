#ifndef __VERTEX_BUFFER_HPP
# define __VERTEX_BUFFER_HPP
# include <glib_internals.hpp>

class VertexBuffer {
private:
    GLuint                   buffer_id;
    const std::vector<float> v_positions;

    VertexBuffer() = delete;

public:
    VertexBuffer(const std::vector<float> &, unsigned int);
    VertexBuffer(const std::vector<float> &, unsigned int, GLuint);
    VertexBuffer(const VertexBuffer &);

    ~VertexBuffer();

    GLuint GetId() const;

    void Bind() const;
    void Release() const;
};

#endif //__VERTEX_BUFFER_HPP
