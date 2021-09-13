#include "treewindow.hpp"
#include "DequeCellRendererText.hpp"

TreeWindow::TreeWindow()
{
    // Create data store
    m_refTreeModel = Gtk::TreeStore::create(m_Columns);
    m_TreeView.set_model(m_refTreeModel);

    // Create the custom cell renderer
    DequeCellRendererText *ids_cell = 
                                    Gtk::make_managed<DequeCellRendererText>();

    // Set visible columns
    int col_index = m_TreeView.append_column ("IDs", *ids_cell);

    // Set the correct property to store the data
    Gtk::TreeViewColumn *pColumn = m_TreeView.get_column(col_index - 1);
    if(pColumn != NULL)
    {
        pColumn->add_attribute(ids_cell->property_deque(), m_Columns.m_col_ids);
    }

    m_TreeView.append_column ("Name", m_Columns.m_col_name);

    // Add some data
    std::deque<unsigned short> ids = {4, 2, 0};
    // Gtk::TreeModel::iterator is a pointer to Gtk::Model::Row
    // In this case we only need the row itself
    Gtk::TreeModel::Row row = *m_refTreeModel->append();
    row[m_Columns.m_col_ids] = ids;
    row[m_Columns.m_col_name] = "Gtkmm4";

    // add treeview to window
    set_child(m_TreeView);
}

TreeWindow::~TreeWindow()
{

}