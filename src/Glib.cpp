#include <Glib.hpp>

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
void GLib::__generate_texture_scene(void)
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

    std::string vertex_shader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";

    std::string fragment_shader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4(1.0, 0.0, 0.0, 1.0);\n"
        "}\n";

    GLuint shader = __create_shader(vertex_shader, fragment_shader);
    GL_wrap(glUseProgram(shader));
    std::cout << "[INFO] init canvas | " << shader << std::endl;

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
    __generate_texture_scene();
}

void    GLib::render(void)
{
    __render_main_loop();
}

GLuint    GLib::__compile_shader(GLuint type, const std::string& code)
{
    GLuint id;
    
    GL_wrap(id = glCreateShader(type));
    const char *src = code.c_str();
    GL_wrap(glShaderSource(id, 1, &src, nullptr));
    GL_wrap(glCompileShader(id));

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int length;
        char *msg;

        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        msg = new char[length * sizeof(char)]; // temp
        glGetShaderInfoLog(id, length, &length, msg);
        std::cerr << "[SHADER] [ERROR] " << msg << std::endl;
        glDeleteShader(id);
    }
    return id;
}

GLuint    GLib::__create_shader(const std::string& vertex_shader, const std::string& fragment_shader)
{
    GLuint program; 
    GL_wrap(program = glCreateProgram());
    GLuint vshader_id = __compile_shader(GL_VERTEX_SHADER, vertex_shader);
    GLuint fshader_id = __compile_shader(GL_FRAGMENT_SHADER, fragment_shader);

    GL_wrap(glAttachShader(program, vshader_id));
    GL_wrap(glAttachShader(program, fshader_id));
    GL_wrap(glLinkProgram(program));
    GL_wrap(glValidateProgram(program));

    GL_wrap(glDeleteShader(vshader_id));
    GL_wrap(glDeleteShader(fshader_id));

    std::cout << "[SHADER] " << program << " | " << vshader_id << " | " << fshader_id << std::endl;
    return program;
    //std:istream vshader_file, fshader_file;
    //vshader_file.open("shaders/canvas_vertex.glsl");
    //fshader_file.open("shaders/canvas_fragment.glsl");

}