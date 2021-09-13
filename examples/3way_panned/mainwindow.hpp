#ifndef GTKMM_EXAMPLE_3WAYPANNED_MAINWINDOW_HPP
#define GTKMM_EXAMPLE_3WAYPANNED_MAINWINDOW_HPP

#include "3way_panned.hpp"

#include <gtkmm/window.h>

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    ~MainWindow();
    
private:
    ThreeWayPanned m_3way_panned;
};

#endif // GTKMM_EXAMPLE_3WAYPANNED_MAINWINDOW_HPP