#include <Glib.hpp>

void GLib::_render_main_loop()
{
    while (!glfwWindowShouldClose(this->__win))
    {
        GL_wrap(glClear(GL_COLOR_BUFFER_BIT));
        GL_wrap(glDrawArrays(GL_TRIANGLES, 0, 3));
        glfwSwapBuffers(__win); // front, back buffers
        glfwPollEvents(); // tal
    }
};