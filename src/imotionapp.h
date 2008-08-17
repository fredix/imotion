/*
 *  imotionapp
 *  Copyright (C) 2008 Frédéric Logier
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Library General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef IMOTIONAPP_H
#define IMOTIONAPP_H

#include <gtkmm.h>
#include <libglademm.h>
#include <iostream>
#include "cameramanager.h"



// gruik !
#define DATADIR "/home/fred/dev/gnome/imotion/trunk/data/"

class ModelColumns : public Gtk::TreeModel::ColumnRecord
{
public:
    ModelColumns ()
    { add(m_effect_name); }

    Gtk::TreeModelColumn<Glib::ustring> m_effect_name;
};


class ImotionApp
{
public:
    ImotionApp ();
    virtual ~ImotionApp ();
    virtual Gtk::Window* get_main_window () const { return m_main; }
    //  virtual Gtk::DrawingArea** get_video() { return &video; };

protected:
    virtual void on_quit_clicked ();
    virtual void on_about_clicked ();
    virtual void on_break_toggled ();
    virtual void on_selection_changed ();
    virtual void on_fullscreen_start ();
    virtual void on_fullscreen_stop ();

    bool on_fullscreen_button_press_event (GdkEventButton* event);


    Glib::RefPtr<Gtk::ListStore> m_effects_ListStore;
    Glib::RefPtr<Gtk::TreeSelection> m_treeSel;

    Gtk::TreeModelColumn<Glib::ustring> m_name_effect;
    Gtk::TreeView *m_treeview_effects;
    Gtk::Window *m_main;
    Gtk::Window *m_window_fullscreen;
    Gtk::DrawingArea *m_video;
    Gtk::DrawingArea *m_draw_fullscreen;
    Gtk::ToolButton *m_quit_button;
    Gtk::ToolButton *m_fullscreen_button;
    Gtk::ToggleToolButton *m_break_button;

    Gtk::ImageMenuItem *m_item_about;
    Gtk::ImageMenuItem *m_item_quit;
    Gtk::ImageMenuItem *m_item_fullscreen;
    Gtk::AboutDialog *m_about_dialog;
    Glib::RefPtr<Gnome::Glade::Xml> m_gui_glade_xml;

    CameraManager m_cameramanager;
    ModelColumns m_columns;
};

#endif // IMOTIONAPP_H
