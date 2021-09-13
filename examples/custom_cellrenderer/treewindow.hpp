#ifndef GTKMM_EXAMPLE_CUSTOM_RENDERER_MAINWINDOW_HPP
#define GTKMM_EXAMPLE_CUSTOM_RENDERER_MAINWINDOW_HPP

#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treeview.h>
#include <gtkmm/treestore.h>
#include <deque>

class TreeWindow : public Gtk::Window
{
public:
    TreeWindow();
    ~TreeWindow();
    
private:

    //Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumns()
        {
            add(m_col_ids);
            add(m_col_name);
        }

        Gtk::TreeModelColumn<std::deque<unsigned short>> m_col_ids;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_Columns;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;
};

#endif // GTKMM_EXAMPLE_CUSTOM_RENDERER_MAINWINDOW_HPP