#include <gtkmm/application.h>

int main(int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create("org.gtkmm.example.3way_panned");
    return app->make_window_and_run<DnDWindow>(argc, argv); //Shows the window and returns when it is closed.
}