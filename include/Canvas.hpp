#ifndef __CANVAS_HPP
# define __CANVAS_HPP

# include <glib_internals.hpp>
# include <vector>

class Canvas // wes un vertex buffer, o contiene un vertex buffer ??
{
    private:
        GLuint _canvas_id;

    public:
        Canvas(void);
        Canvas(GLuint);
        ~Canvas();

        void    Init_canvas(const std::vector<float>&, GLuint);

        GLuint  get_id() const;
        void    set_id(GLuint);

        void    Bind(void) const;
        void    Release(void) const;
};

#endif // __CANVAS_HPP