#include <Texture.hpp>

Texture::Texture(unsigned int w, unsigned int h, unsigned int bpp)
    : texture_id(0), buffer(w * h * bpp), width(w), height(h), bpp(bpp)
{
     glGenTextures(1, &texture_id);
}

Texture::Texture(const Texture& o):texture_id(0), width(o.width), height(o.height), bpp(o.bpp)
{
    buffer.assign(o.buffer.begin(), o.buffer.end());

    GL_wrap(glGenTextures(1, &texture_id));
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

    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    GL_wrap(glBindTexture(GL_TEXTURE_2D_ARRAY, texture_id));
    GL_wrap(glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGBA,
        width, height,0,
        GL_RGBA, GL_UNSIGNED_BYTE,buffer.data())
        );
}

void    Texture::ResetBuffer(void) {

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

