#include <Glib.hpp>
#include <ShaderProgram.hpp>

static void __glib_glfw_error_callback_fn(int error, const char* err_msg)
{
    std::cerr << "[GLFW] [ERROR] GLFW failed with error code: " << error << std::endl;
    std::cerr << "[GLFW] [ERROR] " << err_msg << std::endl;
}

GLib::GLib(void): __win(nullptr), _scene(nullptr)
{
    int status = glfwInit();

    glfwSetErrorCallback(__glib_glfw_error_callback_fn);

    if (status != GLFW_TRUE)
        throw glib_runtime_exception("GLFW init error");
}

GLib::~GLib()
{
    if (__win)
        glfwDestroyWindow(this->__win);
    if (_scene)
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
void GLib::_generate_texture_scene()
{
    _scene = new Canvas({-1.0f, -1.0, 1.0f, -1.0f, 1.0f, 1.0f, -1.0f, 1.0f},
                        sizeof(float) * 8,
                        {0,1,2,0,2,3},
                        sizeof(unsigned int) * 6);
    _scene->Bind();
    GL_wrap(glEnableVertexAttribArray(0));
    GL_wrap(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL));

//    GL_wrap(glGenVertexArrays(1, &VAO_texture));
}

void    GLib::create_context(unsigned int w, unsigned int h)
{
    __win = glfwCreateWindow(w, h, "Test title", NULL, NULL);

    if (!__win)
    {
        throw glib_runtime_exception("window initialization error");
    }
    glfwMakeContextCurrent(__win);

        // hints
    //glfwWindowHint(int hint, int value);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "[GLAD] [ERROR] could not initializate OpenGL" << std::endl; // temporal
        throw glib_runtime_exception("GLAD initialization error");
    }
    // log opengl version
        // glViewport ??
    GL_wrap(glViewport(0, 0, w, h)); //temp
    _generate_texture_scene();
}

void    GLib::render(void)
{
    _render_main_loop();
}