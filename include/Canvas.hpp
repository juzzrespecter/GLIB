#ifndef __CANVAS_HPP
# define __CANVAS_HPP

# include <glib_internals.hpp>
# include <VertexBuffer.hpp>
# include <IndexBuffer.hpp>
#include <ShaderProgram.hpp>

// Canvas se compone de una textura, un shaderprogram, un vertexbuffer y un indexbuffer

class Canvas // wes un vertex buffer, o contiene un vertex buffer ??
{
    private:
        VertexBuffer  *vbo;
        IndexBuffer   *ibo;
        ShaderProgram *sp;


    public:
        Canvas(void);
        ~Canvas();

        void    Init_canvas(const std::vector<float>&, GLuint);

//        void    Bind(void) const;
//        void    Release(void) const;

    // bind y release se tienen que cambiar por un context switch ??

};

#endif // __CANVAS_HPP