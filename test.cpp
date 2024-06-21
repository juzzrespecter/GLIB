#include "include/glib_api.hpp"

int main()
{
    GLib test = GLib();

    test.create_context(600, 600);
    test.render();
}