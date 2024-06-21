#include "../../include/glib_internals.hpp"
#include "../../include/utils.hpp"

// debug options

bool GL_check_error(const char *, const char *, int)
{
    std::cout << "blerg";
    while (GLenum err = glGetError() != GL_NO_ERROR)
    {
        return false;
    }
    return true;
}

void GL_clear_error(void)
{
    while (glGetError() == GL_NO_ERROR);
}

// exception classes

glib_runtime_exception::glib_runtime_exception(void)
    : std::runtime_error("") { }

glib_runtime_exception::glib_runtime_exception(const std::string what)
    : std::runtime_error(what) { }