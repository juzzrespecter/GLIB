#ifndef __SHADER_HPP
# include __SHADER_HPP

# include <glib_internals.hpp>

class Shader
{
    private:
        GLuint shader_id;
        GLenum type;

        Shader(void);
    public:
        Shader(GLuint, const std::string&);
        Shader(const Shader&);
        ~Shader();

        void    Init_shader(GLuint, const std::string&);
        void    Bind(void) const;
        void    Release(void) const;

}

#endif // __SHADER_HPP