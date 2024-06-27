#ifndef __SHADER_PROGRAM_HPP
# define __SHADER_PROGRAM_HPP
# include <glib_internals.hpp>

class ShaderProgram
{
    private:
        GLuint program_id;
        GLuint vertex_id, fragment_id;

        const std::string vertex_path;
        const std::string fragment_path;

        std::string     vertex_src;
        std::string     fragment_src;

        std::string _read_shader_from_file(const std::string&);
        GLuint   _compile_shader(const std::string&, GLenum);

    public:
        ShaderProgram();
        ShaderProgram(const std::string&, const std::string&);
        ShaderProgram(const ShaderProgram&);
        ~ShaderProgram();

        GLuint  GetId(void) const;

        void    Bind(void) const;
        void    Release(void) const;
};

#endif // __SHADER_PROGRAM
