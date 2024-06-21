#ifndef __GLIB_INTERNALS_HPP
# define __GLIB_INTERNALS_HPP

# include <GL/glew.h>
# include <GLFW/glfw3.h>

# include <iostream>

# include "utils.hpp"

# ifdef DEBUG
#  define ASSERT(x) if(!(x)) __builtin_debugtrap
#  define GL_wrap(x) GL_check_error();\
     x;\
     ASSERT(GL_check_error(#x, __FILE__, __LINE__))
# else
#  define GL_wrap(x) x
# endif

# endif // __GLIB_INTERNALS_HPP