#include "include/glib_api.hpp"

# define PIXEL_SIZE 4

static char *generate_espana(int w, int h)
{
    char *buffer = static_cast<char *>(malloc(sizeof(char) * w * h * PIXEL_SIZE));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {

            buffer[i * j * PIXEL_SIZE] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 1] = 0x7f;
            buffer[(i * j * PIXEL_SIZE) + 2] = 0x0;
            buffer[(i * j * PIXEL_SIZE) + 3] = 0xff;
        }
    }
    return buffer;
}

int main()
{
    char    *buffer;
    GLib test = GLib();

    test.create_context(600, 600);
    buffer = generate_espana(600, 600);
    test.add_texture(buffer);
    test.render();
}