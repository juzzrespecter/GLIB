#ifndef __CANVAS_HPP
# define __CANVAS_HPP

# include <glib_internals.hpp>
# include <VertexBuffer.hpp>
# include <IndexBuffer.hpp>
#include <ShaderProgram.hpp>

// Canvas se compone de una textura, un shaderprogram, un vertexbuffer y un indexbuffer
// expect VAO, Texture, Uniform tambien para impllemenetar
class Canvas // wes un vertex buffer, o contiene un vertex buffer ??
{
private:
    VertexBuffer vbo;
    IndexBuffer ibo;
    ShaderProgram sp;
public:
    Canvas() = delete;
    Canvas(const std::vector<float> &, unsigned int,
           const std::vector<unsigned int> &, unsigned int);

    Canvas(const Canvas &);

    ~Canvas();

    void Bind() const;

    void Release() const;

    const ShaderProgram& GetShaderProgram() const;
    const VertexBuffer& GetVertexBuffer() const;
    const IndexBuffer& GetIndexBuffer() const;
};

#endif // __CANVAS_HPP
