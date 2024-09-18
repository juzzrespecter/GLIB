#ifndef __INDEX_BUFFER_HPP
# define __INDEX_BUFFER_HPP

# include <glib_internals.hpp>

class IndexBuffer {
private:
    GLuint buffer_id;

    std::vector<unsigned int> indices;

    IndexBuffer(void) = delete;

public:
    IndexBuffer(const std::vector<unsigned int> &, GLuint);

    IndexBuffer(const std::vector<unsigned int> &); // temp
    IndexBuffer(const IndexBuffer &);

    ~IndexBuffer();

    GLuint GetId() const;

    void Bind() const;

    void Release() const;
};

# endif //__INDEX_BUFFER_HPP
