#include <Glib.hpp>

void GLib::_render_main_loop()
{
    // _texture->Bind();
    while (!glfwWindowShouldClose(_win))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        _scene->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr); // tmp para configuracion
        glfwSwapBuffers(_win); // front, back buffers
        glfwPollEvents(); // tal
    }
}