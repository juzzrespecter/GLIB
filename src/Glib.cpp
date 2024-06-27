#include <Glib.hpp>
#include <ShaderProgram.hpp>

static void __glib_glfw_error_callback_fn(int error, const char* err_msg)
{
    std::cerr << "[GLFW] [ERROR] GLFW failed with error code: " << error << std::endl;
    std::cerr << "[GLFW] [ERROR] " << err_msg << std::endl;
}

GLib::GLib(void)
{
    int status = glfwInit();

    glfwSetErrorCallback(__glib_glfw_error_callback_fn);

    if (status != GLFW_TRUE)
        throw glib_runtime_exception("GLFW init error");
}

GLib::~GLib()
{
    // limpiar escenas
    if (this->__win)
        glfwDestroyWindow(this->__win);

    glfwTerminate();
}

/* Creacion del Vertex Buffer:

    Creamos un buffer (glGenBuffers) y obtenemos el identificador.
    Seleccionamos (bindeamos) el buffer, informamos sobre el tipo de buffer con el 
    que trabajamos.
    Creamos un espacio de memoria para el buffer (se puede asignar ahora o despues)
    (glBufferData)

*/
void GLib::_generate_texture_scene(void)
{
//    GLuint  VAO_texture;

    //static const std::vector<float> canvas_vertices = {
    //    -0.5f, -0.5f,
    //    0.5f, -0.5f,
    //    0.0f, 0.5f
    //};

    static const float canvas_vertices[] = {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    GLuint  buffer_id;
    GL_wrap(glGenBuffers(1, &buffer_id));
    GL_wrap(glBindBuffer(GL_ARRAY_BUFFER, buffer_id));
    GL_wrap(glBufferData(GL_ARRAY_BUFFER, 
        6 * sizeof(float), 
        canvas_vertices,
        GL_STATIC_DRAW));

//    Canvas_scene.Init_canvas(canvas_vertices, 6 * sizeof(float));

    GL_wrap(glEnableVertexAttribArray(0));
    GL_wrap(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), NULL));

    ShaderProgram sp;

    sp.Bind();
    std::cout << "[INFO] init canvas | " << sp.GetId() << std::endl;

    // creamos los buffers para la textura y el lienzo

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