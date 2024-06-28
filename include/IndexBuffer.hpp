#ifndef __INDEX_BUFFER_HPP
# define __INDEX_BUFFER_HPP

# include <glib_internals.hpp>

class IndexBuffer
{
    private:
        GLuint buffer_id;

        IndexBuffer(void) = delete;
    public:
    IndexBuffer(const std::vector<unsigned int>&, unsigned int, GLuint);
        IndexBuffer(const std::vector<unsigned int>&, unsigned int); // temp
        IndexBuffer(const IndexBuffer&);
        ~IndexBuffer();

        void Bind(void) const;
        void Release(void) const;

};

# endif //__INDEX_BUFFER_HPP