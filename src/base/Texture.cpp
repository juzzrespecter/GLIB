#include <Texture.hpp>

Texture::Texture(const std::string&) \
{ 
    
}

Texture::Texture(const Texture& o)
{

}

Texture::~Texture()
{
    glDeleteTextures(texture_id);
}

void    *Texture::CreateNewBuffer(unsigned int, unsigned int, unsigned int)
{

}

void    Texture::ImportBuffer(void *)
{

}

void    Texture::Bind(void) const
{
    GL_wrap(glBindTexture(texture_id));
}

void    Texture::Release(void) const
{
    GL_wrap(glBindTexture(0));
}
