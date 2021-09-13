#include "treewindow.hpp"
#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app =
                Gtk::Application::create("org.gtkmm.example.custom_renderer");
    //Shows the window and returns when it is closed.
    return app->make_window_and_run<TreeWindow>(argc, argv);
}