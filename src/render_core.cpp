#include <Glib.hpp>

void GLib::_render_main_loop()
{
    while (!glfwWindowShouldClose(this->__win))
    {
        GL_wrap(glClear(GL_COLOR_BUFFER_BIT));
        GL_wrap(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr)); // tmp para configuracion
        glfwSwapBuffers(__win); // front, back buffers
        glfwPollEvents(); // tal
    }
};