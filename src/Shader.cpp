#include <Shader.hpp>

Shader::Shader(void): shader_id(0) { }

Shader::Shader(GLuint type, const std::string& shader_path): type(type) 
{ 
    std::istream        shader_file(shader_path);
    std::stringstream   buffer; // para revisar
    const char          *src;

    if (!shader_file.is_open())
    {
        // pendiente control de errores
    }
    buffer << shader_file;
    src = buffer.str();

    GL_wrap(shader_id = glCreateShader(type));
    GL_wrap(glShaderSource(&shader_id, src));
    GL_wrap(glCompileShader(shader_id));
}