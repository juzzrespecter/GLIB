#include <Texture.hpp>

Texture::Texture(unsigned int w, unsigned int h, unsigned int bpp)
    : buffer(w * h * bpp), width(w), height(h), bpp(bpp)
{
     glGenTextures(1, &texture_id);
}

Texture::Texture(const Texture& o): width(o.width), height(o.height), bpp(o.bpp)
{
    buffer.assign(o.buffer.begin(), o.buffer.end());
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture_id); // TODO
}

void    Texture::Bind(void) const
{
    GL_wrap(glBindTexture(GL_TEXTURE_2D, texture_id));
}

void    Texture::Release(void) const
{
    GL_wrap(glBindTexture(GL_TEXTURE_2D, 0));
}

void    Texture::SetBuffer(const char* buffer_array)
{

    std::string buffer_string(buffer_array);

    buffer.assign(buffer_string.begin(),
                  buffer_string.end());
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

