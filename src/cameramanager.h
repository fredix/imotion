/*
 *  ui
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


#ifndef CAMERAMANAGER_H
#define CAMERAMANAGER_H

#include <gstreamermm.h>
#include <gtkmm.h>
#include <gst/interfaces/xoverlay.h>
#include <gdk/gdkx.h>

class CameraManager
{
 public:
  CameraManager();
  virtual ~CameraManager();

  void play_cam();
  void switch_effect(const gchar *effect_name);
  void pause_cam();
  void replay_cam();

  //  std::string *effect_name;
  const gchar *effect_name;
  Gtk::DrawingArea **video;

 protected:
  void stop_cam();
  GstElement *pipeline, *bin, *source, *filter, *videoscale, *effect, *sink;
  GstBus *bus;
};

#endif // CAMERAMANAGER_H
