#include <ShaderProgram.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>

void    ShaderProgram::__read_shader_from_file(void)
{
    std::ifstream   vshader_file(vertex_path);
    std::ifstream   fshader_file(fragment_path);

    if (!vshader_file.is_open())
    {
        throw std::runtime_error("bad"); // TODO: logger, refactor custom exceptions
    }

}

ShaderProgram::ShaderProgram()
    : vertex_path("./shaders/canvas_vertex.glsl"),
      shader_path("./shaders/canvas_fragment.glsl")
{

}

ShaderProgram::ShaderProgram(const std::string& vpath, const std::string& fpath)
    : vertex_path(vpath), fragment_path(fpath)
{

}

ShaderProgram::ShaderProgram(const ShaderProgram& o)
{

}

ShaderProgram::~ShaderProgram()
{

}


GLuint  ShaderProgram::GetId(void) const
{   
    return _program_id;
}

void    ShaderProgram::Bind(void) const
{

}

void    ShaderProgram::Release(void) const
{

}
