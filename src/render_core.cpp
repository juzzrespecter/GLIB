#include <Glib.hpp>

void GLib::__render_main_loop()
{
    while (!glfwWindowShouldClose(this->__win))
    {
        GL_wrap(glClear(GL_COLOR_BUFFER_BIT));

        glfwSwapBuffers(__win); // front, back buffers
        GL_wrap(glDrawArrays(GL_TRIANGLES, 0, 3));
        glfwPollEvents(); // tal
    }
};