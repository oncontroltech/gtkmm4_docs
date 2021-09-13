#ifndef GTKMM_EXAMPLE_3WAYPANNED_3WAYPANNED_HPP
#define GTKMM_EXAMPLE_3WAYPANNED_3WAYPANNED_HPP

#include <gtkmm/frame.h>
#include <gtkmm/separator.h>
#include <gtkmm/box.h>

class ThreeWayPanned : public Gtk::Box
{
public:
    ThreeWayPanned();
    ~ThreeWayPanned();

private:
    Gtk::Frame m_left_widget;
    Gtk::Separator m_left_separator;
    Gtk::Frame m_center_widget;
    Gtk::Separator m_right_separator;
    Gtk::Frame m_right_widget;

    void drop_motion_event(double x, double y);
};

#endif // GTKMM_EXAMPLE_3WAYPANNED_3WAYPANNED_HPP