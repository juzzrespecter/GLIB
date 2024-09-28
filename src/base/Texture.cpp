#include <Texture.hpp>

Texture::Texture(): width(0), height(0), bpp(0) {
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture_id);
}

Texture::Texture(unsigned int w, unsigned int h, unsigned int bpp)
    : texture_id(0), buffer(w * h * bpp), width(w), height(h), bpp(bpp)
{
     glGenTextures(1, &texture_id);
     glBindTexture(GL_TEXTURE_2D_ARRAY, texture_id);
}

Texture::Texture(const Texture& o):texture_id(0), width(o.width), height(o.height), bpp(o.bpp)
{
    buffer.assign(o.buffer.begin(), o.buffer.end());

    glGenTextures(1, &texture_id);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture_id); // TODO
}

void    Texture::Bind() const
{
    glBindTexture(GL_TEXTURE_2D_ARRAY, texture_id);
}

void    Texture::Release() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void    Texture::SetBuffer(const std::vector<unsigned char> &buffer) const
{
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D_ARRAY, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D_ARRAY, texture_id);
    glTexImage2D(
        GL_TEXTURE_2D, 0, GL_RGB,
        width, height,0,
        GL_RGB, GL_UNSIGNED_BYTE,buffer.data());
}

void    Texture::ResetBuffer() {

}

unsigned int    Texture::GetMaxSize() const {
    return (width * height * bpp);
}

unsigned int    Texture::GetWidth() const {
    return (width);
}

unsigned int    Texture::GetHeight() const {
    return (height);
}

unsigned int    Texture::GetBitsPerPixel() const {
    return (bpp);
}

