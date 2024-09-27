#include <charconv>
#include <Glib.hpp>
#include <ShaderProgram.hpp>

void GLib::_glfw_error_callback_fn(int error, const char *err_msg) {
    std::cerr << "[GLFW] [ERROR] GLFW failed with error code: " << error << std::endl;
    std::cerr << "[GLFW] [ERROR] " << err_msg << std::endl;
}

void GLib::_gl_debug_callback_fn( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam ) {
    (void) source, (void) id, (void) length, (void) userParam;

    std::string err_type = (type == GL_DEBUG_TYPE_ERROR) ? " [ERROR] " : " ";
    std::cerr << "[GL] [DEBUG]" << err_type;
    std::cerr << std::hex << "0x" << type << " ";;
    std::cerr << std::hex << "0x" << severity << " ";
    std::cerr << message << std::dec << std::endl;
}

GLib::GLib(): _win(nullptr) {
    int status = glfwInit();

    glfwSetErrorCallback(_glfw_error_callback_fn);

    if (status != GLFW_TRUE)
        throw glib_runtime_exception("GLFW init error");
}

GLib::~GLib() {
    if (_win)
        glfwDestroyWindow(this->_win);
    if (_texture)
        delete _texture;
    glfwTerminate();
}

/** Creacion del Vertex Buffer:

    Creamos un buffer (glGenBuffers) y obtenemos el identificador.
    Seleccionamos (bindeamos) el buffer, informamos sobre el tipo de buffer con el 
    que trabajamos.
    Creamos un espacio de memoria para el buffer (se puede asignar ahora o despues)
    (glBufferData)

*/

// esta funcion se expone, aqui se crea dinamicame nte el canvas
// impliaciones en ell flujo predefinido del RT ??

// la creacionb del buffer ya tienen en cuenta las coordenadas de textura
// la textura es un attributo del vertex, se anyade una config para el VAO
void GLib::_generate_texture_scene() {
    _scene = new Canvas();
    //VertexBufferLayout buffer_layout;;
    //buffer_layout.Push<GLfloat>(3);
    //buffer_layout.Push<GLfloat>(2);
    //_scene_vao = new VAO();
    //_scene_vao->AddBuffer(_scene->GetVertexBuffer(), buffer_layout);
    //GL_wrap(glEnableVertexAttribArray(0));
    //GL_wrap(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr));
}

void GLib::create_context(unsigned int w, unsigned int h) {
    _win = glfwCreateWindow(w, h, "Test title", nullptr, nullptr);

    if (!_win) {
        throw glib_runtime_exception("window initialization error");
    }
    glfwMakeContextCurrent(_win);

    // hints
    //glfwWindowHint(int hint, int value);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cerr << "[GLAD] [ERROR] could not initializate OpenGL" << std::endl; // temporal
        throw glib_runtime_exception("GLAD initialization error");
    }
    // glViewport ??
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    GL_wrap(glViewport(0, 0, w, h)); //temp

#ifdef DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(_gl_debug_callback_fn, 0);
#endif

    _generate_texture_scene();
}

/**
 * Delegamos la gestion del tamanyo de la textura en la configuracion global de la escena.
 * @param data
 */
void GLib::add_texture(int w, int h, const std::vector<unsigned char> &data) {
    _texture = new Texture(w, h, 3);
    _texture->SetBuffer(data);
}

/**
 * Definicion temporal
 */
void GLib::render() {
    _render_main_loop();
}
