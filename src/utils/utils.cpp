#include <glib_internals.hpp>
#include <utils.hpp>

// debug options

bool GL_check_error(const char *fn, const char *file, int line)
{
    std::cerr << "[GL] Called " << fn << std::endl;
    while (GLenum err = glGetError() != GL_NO_ERROR)
    {
        std::cerr << "[GL] [ERROR] " << err << std::endl;
        std::cerr << "[GL] [ERROR] " << fn << " | " << file << " | " << line << std::endl;
        return false;
    }
    return true;
}

void GL_clear_error(void)
{
    while (glGetError() != GL_NO_ERROR);
}

// exception classes

glib_runtime_exception::glib_runtime_exception(void)
    : std::runtime_error("") { }

glib_runtime_exception::glib_runtime_exception(const std::string what)
    : std::runtime_error(what) { }