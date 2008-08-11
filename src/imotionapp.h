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

  ModelColumns()
    { add(effect_name); }

  Gtk::TreeModelColumn<Glib::ustring> effect_name;
};


class ImotionApp
{
  CameraManager m_cameramanager;

 public:
  ImotionApp();
  virtual ~ImotionApp();
  virtual Gtk::Window* get_main_window() const { return main; }
  //  virtual Gtk::DrawingArea** get_video() { return &video; };

 protected:
  virtual void on_quit_clicked();
  virtual void on_about_clicked();
  virtual void on_break_toggled();
  virtual void on_selection_changed();

  Glib::RefPtr<Gtk::ListStore> effects_ListStore;
  Glib::RefPtr<Gtk::TreeSelection> treeSel;

  Gtk::TreeModelColumn<Glib::ustring> name_effect;
  Gtk::TreeView *treeview_effects;
  Gtk::Window *main;
  Gtk::DrawingArea *video;
  Gtk::ToolButton *quit_button;
  Gtk::ToggleToolButton *break_button;

  Gtk::ImageMenuItem *item_about;
  Gtk::ImageMenuItem *item_quit;
  Gtk::ImageMenuItem *item_fullscreen;
  Gtk::AboutDialog *about_dialog;
  Glib::RefPtr<Gnome::Glade::Xml> gui_glade_xml;

  GList* effects;
  GList* effect;
  GstElementFactory *tmp;

  ModelColumns columns;
};

#endif // IMOTIONAPP_H
