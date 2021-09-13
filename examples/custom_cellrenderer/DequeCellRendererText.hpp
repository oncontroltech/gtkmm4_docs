
#ifndef GUI_GRAPHICS_WORKSPACE_PROJECTTREE_DEQUECELLRENDERERTEXT_HH
#define GUI_GRAPHICS_WORKSPACE_PROJECTTREE_DEQUECELLRENDERERTEXT_HH

#include <deque>

#include <gtkmm/cellrenderertext.h>
#include <glibmm/property.h>

//! @brief Custom CellRenderer
//!
//! This CellRenderer class inherits from the Gtk::CellRendererText class
//! It accepts a property "deque" which is a std::deque
//! and it mounts a string with the values inside it to be displayed
//!
//! The display format is "X, X, X, ...", where X are the values from the deque
//!
//!
class DequeCellRendererText : public Gtk::CellRendererText
{
public:
    //! @brief Class constructor
    //!
    DequeCellRendererText();

    //! @brief Class destructor that overrides the CellRendererText destructor
    //!
    ~DequeCellRendererText() override;

    //! @brief Property Proxy that allow to read and write the deque property
    //!
    Glib::PropertyProxy<std::deque<unsigned short>> property_deque();

private:

    //! @brief Property "deque", it contains a std::deque of unsigned short
    //!
    Glib::Property<std::deque<unsigned short>> m_property_deque;

    //! @brief Updates the text property of CellRendererText with deque
    //!
    void on_deque_change();
};

#endif // GUI_GRAPHICS_WORKSPACE_PROJECTTREE_DEQUECELLRENDERERTEXT_HH
