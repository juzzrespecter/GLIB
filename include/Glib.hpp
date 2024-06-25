#ifndef __GLIB_HPP
# define __GLIB_HPP
# include <glib_internals.hpp>
# include <Canvas.hpp>

class GLib
{
    private:
        GLFWwindow  *__win;
        Canvas      Canvas_scene;

            // array de clases que contengan elementos generados dinamicamente
        void    __generate_texture_scene(void);

        GLuint  __compile_shader(GLuint, const std::string&);
        GLuint  __create_shader(const std::string&, const std::string&);


        void    __render_main_loop(void);
//            void __switch_to_dynamic_config()

    public:
        GLib(void);
        ~GLib(void);

        void create_context(unsigned int, unsigned int);
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