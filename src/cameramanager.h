/*
 *  cameramanager
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

#include <iostream>
#include <gstreamermm.h>
#include <gtkmm.h>
#include <gst/interfaces/xoverlay.h>
#include <gdk/gdkx.h>

class CameraManager
{
public:
    CameraManager ();
    virtual ~CameraManager ();

    void set_video (Gtk::DrawingArea **a_video);
    void play_cam ();
    void switch_effect (Glib::ustring a_name);
    void pause_cam ();
    void replay_cam ();
    void restart ();

protected:
    void stop_cam ();
    Gtk::DrawingArea **m_video;
    Glib::ustring m_effect_name;
    GstElement *m_pipeline, *m_bin, *m_source, *m_filter, *m_videoscale, *m_effect, *m_sink;
    GstBus *m_bus;
};

#endif // CAMERAMANAGER_H
