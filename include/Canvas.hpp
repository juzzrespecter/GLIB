#ifndef __CANVAS_HPP
# define __CANVAS_HPP

# include <glib_internals.hpp>
# include <VertexBuffer.hpp>
# include <IndexBuffer.hpp>
#include <ShaderProgram.hpp>
#include <VAO.hpp>

// Canvas se compone de una textura, un shaderprogram, un vertexbuffer y un indexbuffer
// expect VAO, Texture, Uniform tambien para impllemenetar

// la textura es completamente independiente del canvas
class Canvas // wes un vertex buffer, o contiene un vertex buffer ??
{
private:
    VertexBuffer  vbo;
    IndexBuffer   ibo;
    ShaderProgram sp;
    VAO           vao;

    /* Canvas vertex attribute info */
    const std::vector<float> Canvas_VertexData = {
        -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f,  1.0f, 0.0f,
         1.0f, 1.0f,   1.0f, 1.0f,
        -1.0f, 1.0f,   0.0f, 1.0f
    };

    const std::vector<unsigned int> Canvas_IndexData = {
        0, 1, 2, 0, 2, 3
    };

public:
    Canvas();

    Canvas(const Canvas &);

    ~Canvas();

    void Bind() const;

    void Release() const;

    const ShaderProgram& GetShaderProgram() const;
    const VertexBuffer& GetVertexBuffer() const;
    const IndexBuffer& GetIndexBuffer() const;
};

#endif // __CANVAS_HPP
