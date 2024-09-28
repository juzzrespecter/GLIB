#include <ShaderProgram.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept> // tmp
#include <string>

GLuint    ShaderProgram::_compile_shader(const std::string& src, GLenum type)
{
    GLuint  shader_id;
    const char *_src = src.c_str();

    shader_id = glCreateShader(type);
    glShaderSource(shader_id, 1, &_src, nullptr);
    glCompileShader(shader_id);

    int compile_res;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &compile_res);
    if (compile_res == GL_FALSE)
    {
        int     len_msg;
        char    *msg;

        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &len_msg);
        msg = new char[len_msg * sizeof(char)];
        glGetShaderInfoLog(shader_id, len_msg, &len_msg, msg);
        std::cerr << "[OPENGL] [SHADER] [ERROR] " << msg << std::endl; // TODO refactor to log
        delete [] msg;
        throw std::runtime_error("Shader compiler exception"); // TODO refactor exc
    }
    return (shader_id);
}

std::string    ShaderProgram::_read_shader_from_file(const std::string& path)
{
    std::ifstream   shader_file(path.c_str(), std::ios::ate);

    if (!shader_file.is_open())
    {
        throw std::runtime_error("Shader file open extension"); // TODO: logger, refactor custom exceptions
    }
    std::ifstream::pos_type len_shader = shader_file.tellg();
    shader_file.seekg(0);
    std::vector<char> buffer(len_shader);
    shader_file.read(buffer.data(), len_shader);
    std::cout << "Read shader from file" << std::endl;
    return (std::string(buffer.data(), len_shader));
}

ShaderProgram::ShaderProgram()
    : vertex_path("./src/shaders/canvas_vertex.glsl"),
      fragment_path("./src/shaders/canvas_fragment.glsl")
{
    program_id = glCreateProgram();
    vertex_src = _read_shader_from_file(vertex_path);
    fragment_src = _read_shader_from_file(fragment_path);

    vertex_id = _compile_shader(vertex_src, GL_VERTEX_SHADER);
    fragment_id = _compile_shader(fragment_src, GL_FRAGMENT_SHADER);

    glAttachShader(program_id, vertex_id);
    glAttachShader(program_id, fragment_id);
    glLinkProgram(program_id);
    glValidateProgram(program_id);
}

ShaderProgram::ShaderProgram(const std::string& vpath, const std::string& fpath)
    : vertex_path(vpath), fragment_path(fpath)
{

}

ShaderProgram::ShaderProgram(const ShaderProgram& o)
    : vertex_path(o.vertex_path), fragment_path(o.fragment_path)
{

}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(program_id);
    glDeleteShader(vertex_id);
    glDeleteShader(fragment_id);
}


GLuint  ShaderProgram::GetId() const
{   
    return (program_id);
}

void    ShaderProgram::Bind() const
{
    glUseProgram(program_id);
}

void    ShaderProgram::Release(void) const
{
    glUseProgram(0);
}
