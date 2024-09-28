#include "include/glib_api.hpp"

# define PIXEL_SIZE 3

std::vector<unsigned char> generate_espana(int w, int h)
{
    std::vector<unsigned char> buffer;

    int i = 0;
    for (; i < h / 3; i++)
    {
        for (int j = 0; j < w; j++)
        {
            buffer.push_back(0xff);
            buffer.push_back(0xff);
            buffer.push_back(0x0);
        }
    }
    for (; i < h - (h/3); i++) {
         for (int j = 0; j < w; j++) {
            buffer.push_back(0xff);
            buffer.push_back(0x0);
            buffer.push_back(0x0);
           }
      }
    for (; i < h; i++) {
         for (int j = 0; j < w; j++) {
            buffer.push_back(0xff);
            buffer.push_back(0xff);
            buffer.push_back(0x0);
           }
       }
    std::cout << buffer.size() << ", " << h * w * 3 << std::endl;
    return buffer;
}

int main()
{
    GLib test = GLib();

    test.create_context(600, 600);
    std::vector<unsigned char> buffer = generate_espana(600, 600);
    test.add_texture(600, 600, buffer);
    test.render();
}