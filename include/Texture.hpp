#ifndef __TEXTURE_HPP
# define __TEXTURE_HPP
# include <glib_internals.hpp>

class Texture
{
    private:
        GLuint  texture_id;
        void    *buffer;

        unsigned int width, height, bpp;

        Texture() = delete;
    public:
        Texture(const std::string&);
        Texture(const Texture&);
        ~Texture();

        GLuint  GetId(void) const;

        void    *CreateNewBuffer(unsigned int, unsigned int, unsigned int);
        void    ImportBuffer(void *);

        void    Bind(void) const;
        void    Release(void) const;
};

#endif // __TEXTURE_HPP