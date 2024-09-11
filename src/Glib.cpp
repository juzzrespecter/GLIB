#include <Glib.hpp>
#include <ShaderProgram.hpp>

void GLib::_glfw_error_callback_fn(int error, const char *err_msg) {
    std::cerr << "[GLFW] [ERROR] GLFW failed with error code: " << error << std::endl;
    std::cerr << "[GLFW] [ERROR] " << err_msg << std::endl;
}

GLib::GLib(): _win(nullptr), _scene(nullptr) {
    int status = glfwInit();

    glfwSetErrorCallback(_glfw_error_callback_fn);

    if (status != GLFW_TRUE)
        throw glib_runtime_exception("GLFW init error");
}

GLib::~GLib() {
    if (_win)
        glfwDestroyWindow(this->_win);
    delete _scene;
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
void GLib::_generate_texture_scene() {
    _scene = new Canvas({-1.0f, -1.0, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f},
                        sizeof(float) * 8,
                        {0, 1, 2, 0, 2, 3},
                        sizeof(unsigned int) * 6);
    _scene->Bind();
    GL_wrap(glEnableVertexAttribArray(0));
    GL_wrap(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr));

    //    GL_wrap(glGenVertexArrays(1, &VAO_texture));
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
    // log opengl version
    // glViewport ??
    GL_wrap(glViewport(0, 0, w, h)); //temp
    _generate_texture_scene();
}

/**
 * Delegamos la gestion del tamanyo de la textura en la configuracion global de la escena.
 * @param data
 */
void GLib::add_texture(int w, int h, const std::vector<char> &data) {
    (void) data;

    _texture = new Texture(w, h, 3);
    _texture->SetBuffer(data.data());
}

/**
 * Definicion temporal
 */
void GLib::render() {
    _render_main_loop();
}
