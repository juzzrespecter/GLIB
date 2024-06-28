#ifndef __VERTEX_BUFFER_HPP
# define __VERTEX_BUFFER_HPP
# include <glib_internals.hpp>

class VertexBuffer {
private:
    GLuint                   vertex_id;
    const std::vector<float> v_positions;

    VertexBuffer(void) = delete;

public:
    VertexBuffer(const std::vector<float> &); // darle una vuelta a eso
    VertexBuffer(const VertexBuffer &);

    ~VertexBuffer();

    GLuint GetId(void) const;
};

#endif //__VERTEX_BUFFER_HPP
