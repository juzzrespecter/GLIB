#ifndef __INDEX_BUFFER_HPP
# define __INDEX_BUFFER_HPP

# include <glib_internals.hpp>

class IndexBuffer
{
    private:
        GLuint buffer_id;

        IndexBuffer(void);
    public:
//        IndexBuffer(std::vector<);
        IndexBuffer(const IndexBuffer&);
        ~IndexBuffer();

};

# endif //__INDEX_BUFFER_HPP