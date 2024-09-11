#ifndef __GLIB_HPP
# define __GLIB_HPP
# include <glib_internals.hpp>
# include <Canvas.hpp>
# include <VertexBuffer.hpp>
# include <IndexBuffer.hpp>
#include <Texture.hpp>

class GLib {
private:
    unsigned int Window_Height;
    unsigned int Window_Width;

    GLFWwindow *_win;
    Canvas *_scene;
    Texture *_texture; // temporal para prueba

    // array de clases que contengan elementos generados dinamicamente
    static void _glfw_error_callback_fn(int, const char*);
    void _generate_texture_scene();

    void _render_main_loop();

    //            void __switch_to_dynamic_config()

public:
    GLib();

    /**
     * Contructor con parametros de ventana.
     */
    GLib(unsigned int, unsigned int);

    ~GLib();

    void create_context(unsigned int, unsigned int);

    void add_texture(int, int, const std::vector<char> &);

    void render(); // temporal
    //            void create_scene_buffer();
    // // //            void destroy_scene_buffer();
    //            void init_rendering();
    //            void switch_context();
};


// planteamiento de contexto,
// vector de contextos, se almacenan las vistas a renderizar
// en el proyecto probablemente se trabaje con lista de un solo nodo

// como cambiamos de econfiguracion de escena en mitad de la movida

//class GLib_ctx
//{
//
//};

#endif //__GLIB_HPP
