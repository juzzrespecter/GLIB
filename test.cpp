#include "include/glib_api.hpp"

# define PIXEL_SIZE 3

static char *generate_espana(int w, int h)
{
    char *buffer = static_cast<char *>(malloc(sizeof(char) * w * h * PIXEL_SIZE));

    int i = 0;
    for (; i < h / 3; i++)
    {
        for (int j = 0; j < w; j++)
        {
            buffer[i * j * PIXEL_SIZE] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 1] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 2] = 0x0;
        }
    }
    for (; i < h - (h/3); i++) {
         for (int j = 0; j < w; j++) {
           buffer[i * j * PIXEL_SIZE] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 1] = 0x0;
            buffer[(i * j * PIXEL_SIZE) + 2] = 0x0;
           }
      }
     for (; i < h; i++) {
for (int j = 0; j < w; j++) {
           buffer[i * j * PIXEL_SIZE] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 1] = 0xff;
            buffer[(i * j * PIXEL_SIZE) + 2] = 0x0;
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
    std::string buffer_string(buffer);
    std::vector<char> buffer_vector(buffer_string.begin(), buffer_string.end());
    test.add_texture(600, 600, buffer_vector);
    test.render();
}