#include "clock.h"
#include <gtkmm/main.h>
#include <gtkmm/window.h>

int main(int argc, char** argv)
{
   Gtk::Main kit(argc, argv);

   Gtk::Window win;
   win.set_title("Cairomm Clock");

   Clock c;
   win.add(c);
   c.show();

   Gtk::Main::run(win);

   return 0;
}
