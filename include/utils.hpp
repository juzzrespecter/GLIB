#ifndef __UTILS_HPP
# define __UTILS_HPP

#include <stdexcept>

bool GL_check_error(const char *, const char *, int);
void GL_clear_error();

class glib_runtime_exception: public std::runtime_error
{
    protected:
        glib_runtime_exception();

    public:
        glib_runtime_exception(const std::string&);

};

#endif //__UTILS_HPP