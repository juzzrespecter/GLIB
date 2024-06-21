#ifndef __CANVAS_HPP
# define __CANVAS_HPP

# include <glib_internals.hpp>

class Canvas
{
    private:
        GLuint _canvas_id;

    public:
        Canvas(void);
        Canvas(GLuint);
        ~Canvas();

        GLuint  get_id() const;

    
};

#endif // __CANVAS_HPP