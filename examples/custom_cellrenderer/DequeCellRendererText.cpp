#include "DequeCellRendererText.hpp"

//! Initialization of the custom CellRenderer object
//! and default value of the deque property
//!
DequeCellRendererText::DequeCellRendererText() :
    Glib::ObjectBase (typeid(DequeCellRendererText)),
    Gtk::CellRendererText (),
    m_property_deque (*this, "deque", {})
{
    // Connects the signal to make the convertion when deque is updated
    property_deque().signal_changed().connect(sigc::mem_fun(*this, &DequeCellRendererText::on_deque_change));
}

//! DequeCellRendererText destructor
//!
DequeCellRendererText::~DequeCellRendererText ()
{

}

//! Gets the proxy of the deque property
//! to allow to read and write to it
//!
Glib::PropertyProxy<std::deque<unsigned short>>
DequeCellRendererText::property_deque ()
{
    return m_property_deque.get_proxy();
}

//! Does the convertion of the std::deque to std::string
//! and updates the text property of the CellRendererText
//! and waits for the CellRendererText to render the text
//!
void
DequeCellRendererText::on_deque_change()
{
    std::deque<unsigned short> numbers = property_deque();
    // Create the string with the deque values
    Glib::ustring str = "";

    // If the deque isn't empty
    if (numbers.empty() == false)
    {
        // Appends the first number to the string
        str = std::to_string(numbers[0]);

        // If more numbers iterate and append them using "," as separator
        for (unsigned int it = 1; it < numbers.size(); ++it)
        {
            str += "," + std::to_string(numbers[it]);
        }
    }

    // Puts the string to the text property
    property_text() = str;
}
