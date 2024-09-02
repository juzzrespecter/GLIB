#ifndef TEXTURE_HPP
# define TEXTURE_HPP
# include <glib_internals.hpp>
# include <vector>

// la textura es el buffer

class Texture
{
    private:
        GLuint              texture_id;
        std::vector<char>   buffer;

        const unsigned int width, height, bpp;


    public:
    Texture() = delete;
        Texture(unsigned int, unsigned int, unsigned int);
        Texture(const Texture&);
        ~Texture();

        GLuint  GetId() const;

        void    Bind() const;
        void    Release() const;

        void    SetBuffer(const char*);
        void  ResetBuffer();

        unsigned int    GetMaxSize() const;
        unsigned int    GetWidth() const;
        unsigned int    GetHeight() const;
        unsigned int    GetBitsPerPixel() const;
};

#endif // TEXTURE_HPP