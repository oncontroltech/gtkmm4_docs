#include "3way_panned.hpp"

#include <gtkmm/droptarget.h>
#include <gtkmm/dragsource.h>
#include <gtkmm/dropcontrollermotion.h>

#include <iostream>

ThreeWayPanned::ThreeWayPanned()
{
    m_left_widget.set_label("Left Widget");
    m_center_widget.set_label("Center Widget");
    m_right_widget.set_label("Right Widget");

    m_left_widget.set_expand(true);
    m_center_widget.set_expand(true);
    m_right_widget.set_expand(true);

    m_left_separator.set_size_request(15, -1);
    m_right_separator.set_size_request(15, -1);

    append(m_left_widget);
    append(m_left_separator);
    append(m_center_widget);
    append(m_right_separator);
    append(m_right_widget);

    /*const GType ustring_type = Glib::Value<Glib::ustring>::value_type();
    Glib::RefPtr<Gtk::DropTarget> drop =
                                Gtk::DropTarget::create(ustring_type,
                                                        Gdk::DragAction::COPY |
                                                        Gdk::DragAction::MOVE);
    
    drop->signal_drop().connect(
                        sigc::mem_fun(*this, &ThreeWayPanned::drop_event), 
                                        false);
    m_left_widget.add_controller(drop);
    m_center_widget.add_controller(drop);
    m_right_widget.add_controller(drop);

    Glib::RefPtr<Gtk::DragSource> drag = Gtk::DragSource::create();
    Glib::Value<Glib::ustring> value;
    value.init(value.value_type());
    value.set("I'm data");
    Glib::RefPtr<Gdk::ContentProvider> content =
                                        Gdk::ContentProvider::create(value);
    drag->set_content(content);
    drag->set_actions(Gdk::DragAction::COPY | Gdk::DragAction::MOVE);
    drag->signal_motion().connect(
                    sigc::mem_fun(*this, &ThreeWayPanned::drag_event_leave));

    m_left_separator.add_controller(drag);
    m_right_separator.add_controller(drag);*/

    Glib::RefPtr<Gtk::DragSource> left_drag_controller =
                                                    Gtk::DragSource::create();
    left_drag_controller->set_actions(Gdk::DragAction::COPY | 
                                        Gdk::DragAction::MOVE);
    m_left_separator.add_controller(left_drag_controller);
    Glib::RefPtr<Gtk::DragSource> right_drag_controller =
                                                    Gtk::DragSource::create();
    right_drag_controller->set_actions(Gdk::DragAction::COPY | 
                                        Gdk::DragAction::MOVE);
    m_right_separator.add_controller(right_drag_controller);

    Glib::RefPtr<Gtk::DropControllerMotion> left_motion_controller = 
                                        Gtk::DropControllerMotion::create();
    left_motion_controller->signal_motion().connect(
                    sigc::mem_fun(*this, &ThreeWayPanned::drop_motion_event));
    m_left_widget.add_controller(left_motion_controller);

    Glib::RefPtr<Gtk::DropControllerMotion> center_motion_controller = 
                                        Gtk::DropControllerMotion::create();
    center_motion_controller->signal_motion().connect(
                    sigc::mem_fun(*this, &ThreeWayPanned::drop_motion_event));
    m_center_widget.add_controller(center_motion_controller);

    Glib::RefPtr<Gtk::DropControllerMotion> right_motion_controller = 
                                        Gtk::DropControllerMotion::create();
    right_motion_controller->signal_motion().connect(
                    sigc::mem_fun(*this, &ThreeWayPanned::drop_motion_event));
    right_motion_controller->signal_enter().connect(
                    sigc::mem_fun(*this, &ThreeWayPanned::drop_motion_event));
    m_right_widget.add_controller(right_motion_controller);
}

void
ThreeWayPanned::drop_motion_event(double x, double y)
{
    std::cout << "x=" << x << " y=" << y << std::endl;
}


ThreeWayPanned::~ThreeWayPanned()
{

}