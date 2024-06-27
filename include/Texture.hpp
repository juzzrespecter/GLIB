#ifndef __TEXTURE_HPP
# define __TEXTURE_HPP
# include <glib_internals.hpp>
# include <vector>

// la textura es el buffer

class Texture
{
    private:
        GLuint              texture_id;
        std::vector<char>   buffer;

        const unsigned int width, height, bpp;

        Texture() = delete;
    public:
        Texture(unsigned int, unsigned int, unsigned int);
        Texture(const Texture&);
        ~Texture();

        GLuint  GetId(void) const;

        char&   operator[](int);

        void    Bind(void) const;
        void    Release(void) const;

        void    SetBuffer(const char*);

        unsigned int    GetMaxSize(void) const;
        unsigned int    GetWidth(void) const;
        unsigned int    GetHeight(void) const;
        unsigned int    GetBitsPerPixel(void) const;
};

#endif // __TEXTURE_HPP