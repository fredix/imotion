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

#include "cameramanager.h"

static
GstBusSyncReply
//create_window (GstBus * bus, GstMessage * message, GstPipeline * pipeline)
create_window (GstBus * bus, GstMessage * message, Gtk::DrawingArea *data)
{
  // GstXOverlay *sink = GST_X_OVERLAY(user_data);

 // ignore anything but 'prepare-xwindow-id' element messages
 if (GST_MESSAGE_TYPE (message) != GST_MESSAGE_ELEMENT)
   return GST_BUS_PASS;

 if (!gst_structure_has_name (message->structure, "prepare-xwindow-id"))
   return GST_BUS_PASS;

 XID video = gdk_x11_drawable_get_xid( data->get_window()->gobj());

 gst_x_overlay_set_xwindow_id (GST_X_OVERLAY (GST_MESSAGE_SRC (message)), video);

 gst_message_unref (message);

 return GST_BUS_DROP;
}


static
gboolean bus_callback (GstBus *bus,
                       GstMessage *message,
                       gpointer    data)
{
  //  GMainLoop *loop = (GMainLoop *) data;
  g_print ("Got %s message\n", GST_MESSAGE_TYPE_NAME (message));
  switch (GST_MESSAGE_TYPE (message)) {
  case GST_MESSAGE_ERROR: {
    GError *err;
    gchar *debug;
    gst_message_parse_error (message, &err, &debug);
    g_print ("Error: %s\n", err->message);
    g_error_free (err);
    g_free (debug);
    //    g_main_loop_quit (loop);
    break;
  }
  case GST_MESSAGE_EOS:
    /* end-of-stream */
    //    g_main_loop_quit (loop);
    break;
  default:
    /* unhandled message */

    //    gst_x_overlay_set_xwindow_id (GST_X_OVERLAY (GST_MESSAGE_SRC (message)), Cameramanager::pVideo);

    break;
  }
  /* we want to be notified again the next time there is a message
   * on the bus, so returning TRUE (FALSE means we want to stop watching
   * for messages on the bus and our callback should not be called again)
   */
  return TRUE;
}


CameraManager::CameraManager ()
{
}

void
CameraManager::play_cam (Gtk::DrawingArea **video_ui)
{
  pipeline = gst_pipeline_new ("pipeline");
  bin = gst_bin_new ("bin");

  source = gst_element_factory_make ("v4l2src", "video_src");
  if (!source) {
    g_print ("Failed to create source of type 'v4l2src'\n");
    //    return EXIT_FAILURE;
  }


  filter = gst_element_factory_make ("ffmpegcolorspace", "filter");

  effect = gst_element_factory_make ("edgetv", "effect");


  sink = gst_element_factory_make ("ximagesink", "video_sink");

  //   sink = gst_element_factory_make ("sdlvideosink", "video_sink");
  if (!sink) {
    g_print ("Failed to create sink of type 'sdlvideosink'\n");
    //    return EXIT_FAILURE;
  }


  /* set up pipeline */
  gst_bin_add_many (GST_BIN (bin), source, filter, effect, sink, NULL);
  gst_bin_add (GST_BIN (pipeline), bin);
  //gst_element_link (source, sink);
  gst_element_link_many (source, filter, effect, sink, NULL);

  gst_element_set_state (pipeline, GST_STATE_PLAYING);


  bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
  gst_bus_add_watch (bus, bus_callback, NULL);


  gst_bus_set_sync_handler (bus, (GstBusSyncHandler) create_window, *video_ui);

  //  g_signal_connect (bus, "message::error", G_CALLBACK (cb_message_error), NULL);
  //  g_signal_connect (bus, "message::eos", G_CALLBACK (cb_message_eos), NULL);


}

void
CameraManager::stop_cam ()
{
  printf("stop cam\n");
}


void
CameraManager::switch_effect (const gchar *effect_name)
{
  printf("%s\n", effect_name);
}


CameraManager::~CameraManager ()
{
  /* clean up */
  //  gst_element_set_state (pipeline, GST_STATE_NULL);
  //  gst_object_unref (bus);
  //  gst_object_unref (pipeline);
  //  gst_object_unref (GST_OBJECT (source));
  //  gst_object_unref (GST_OBJECT (sink));

  gst_deinit ();
}




