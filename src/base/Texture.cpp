#include <Texture.hpp>

Texture::Texture(unsigned int w, unsigned int h, unsigned int bpp)
    : buffer(w * h * bpp), width(w), height(h), bpp(bpp)
{
     
}

Texture::Texture(const Texture& o)
{

}

Texture::~Texture()
{
    glDeleteTextures(texture_id);
}

void    Texture::Bind(void) const
{
    GL_wrap(glBindTexture(texture_id));
}

void    Texture::Release(void) const
{
    GL_wrap(glBindTexture(0));
}

unsigned int    Texture::GetMaxSize(void) const {
    return (width * height * bpp);
}

unsigned int    Texture::GetWidth(void) const {
    return (width);
}

unsigned int    Texture::GetHeight(void) const {
    return (height);
}

unsigned int    Texture::GetBitsPerPixel(void) const {
    return (bpp);
}

