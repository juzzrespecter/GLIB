#include <numeric>
#include <VAO.hpp>

VertexBufferLayout::VertexBufferLayout(): elements(), stride(0) {
}

VertexBufferLayout::~VertexBufferLayout() {

}

GLuint VertexBufferLayout::GetStride() const {
    return stride;
}

const VertexBufferLayout::GL_vector_element &VertexBufferLayout::GetElements() const {
    return elements;
}

VAO::VAO(): vao_id(0) {
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &vao_id);
}

void VAO::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) const {
    // cada indice es una llamada a enable vertex attrib array
    // cada layout es una llamada a vertexattribpointer
    // checkear diferencia entre vertex array objects y vertex attributes
    Bind();
    vb.Bind();
    const auto& elements = layout.GetElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        auto& element = elements[i];

        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.size, element.type, element.normalized,
            layout.GetStride(), reinterpret_cast<void *>(offset));
        std::cout << "ENABLE: " << i << ", SIZE: " << element.size << ", TYPE: " << element.type;
        std::cout << ", NORM: " << element.normalized << ", STRIDE: " << layout.GetStride();
        std::cout << ", OFFS: " << offset << std::endl;
        offset += element.size * VertexBufferElement::GetSize(element.type);
    }
    // to improve

}

template<>
  void VertexBufferLayout::Push<GLint>(GLint size) {
    elements.push_back({GL_INT, size, GL_FALSE});
    stride += VertexBufferElement::GetSize(GL_INT) * size;
}

template<>
void VertexBufferLayout::Push<GLuint>(GLint size) {
    elements.push_back({GL_UNSIGNED_INT, size, GL_FALSE});
    stride +=  VertexBufferElement::GetSize(GL_UNSIGNED_INT) * size;
}

template<>
void VertexBufferLayout::Push<GLfloat>(GLint size) {
    elements.push_back({GL_FLOAT, size, GL_FALSE});
    stride += VertexBufferElement::GetSize(GL_FLOAT) * size;
}

void VAO::Bind() const {
    glBindVertexArray(vao_id);
}

void VAO::Release() const {
    glBindVertexArray(0);
}

GLuint VAO::GetId() const {
    return vao_id;
}
