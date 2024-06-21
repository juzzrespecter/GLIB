#include "../include/glib.hpp"

void GLib::__render_main_loop()
{
    while (!glfwWindowShouldClose(this->__win))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(this->__win); // front, back buffers
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwPollEvents(); // tal
    }
};