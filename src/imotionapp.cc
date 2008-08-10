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

#include "imotionapp.h"
#include "callback.h"



ImotionApp::ImotionApp ()
{
  main = 0;
  quit_button = 0;
  item_about = 0;
  video = 0;

#ifdef GLIBMM_EXCEPTIONS_ENABLED
  try
    {
      gui_glade_xml = Gnome::Glade::Xml::create(DATADIR "imotion.glade");
    }
  catch(const Gnome::Glade::XmlError& ex)
    {
      std::cerr << ex.what() << std::endl;
      //  exit(1);
    }
#else
  std::auto_ptr<Gnome::Glade::XmlError> error;
  gui_glade_xml = Gnome::Glade::Xml::create(DATADIR "imotion.glade", "", "", error);
  if(error.get())
    {
      std::cerr << error->what() << std::endl;
      //exit(1);
    }
#endif

  //Get the Glade-instantiated Dialog:

  if (gui_glade_xml)
    {
      gui_glade_xml->get_widget("main", main);
    }
  if (main)
  {
    gui_glade_xml->get_widget ("toolbutton_quit", quit_button);
    if(quit_button)
    {
      quit_button->signal_clicked().connect( sigc::mem_fun(*this, &ImotionApp::on_quit_clicked) );
    }

    gui_glade_xml->get_widget ("toolbutton_stop", stop_button);
    if(stop_button)
    {
      stop_button->signal_clicked().connect( sigc::mem_fun(*this, &ImotionApp::on_stop_clicked) );
    }


    gui_glade_xml->get_widget ("imagemenuitem_about", item_about);
    if (item_about)
    {
      item_about->signal_activate().connect( sigc::mem_fun(*this, &ImotionApp::on_about_clicked) );
    }


    gui_glade_xml->get_widget ("treeview_effects", treeview_effects);


    gui_glade_xml->get_widget ("drawingarea_video", video);

    // main->show_all();
    // std::cout << gdk_x11_drawable_get_xid( video->get_window()->gobj()) << "\n";





    effects_ListStore = Gtk::ListStore::create(columns);
    (*treeview_effects).set_model(effects_ListStore);


    Gtk::TreeModel::Row row = *(effects_ListStore->append());
    row[columns.effect_name] = "none";



    // get effectv's plugins
    effects = gst_registry_get_feature_list_by_plugin(gst_registry_get_default(), "effectv");

    for (effect = effects; effect; effect = effect->next) {
      tmp = GST_ELEMENT_FACTORY(effect->data);
      fprintf(stderr, "Found effect: %s\n", GST_PLUGIN_FEATURE_NAME(tmp));
      //  if (!strcmp(GST_PLUGIN_FEATURE_NAME(tmp), VISUALIZATION))
      //  fac = tmp;

      row = *(effects_ListStore->append());
      row[columns.effect_name] = GST_PLUGIN_FEATURE_NAME(tmp);


    }
    g_list_free(effects);


    (*treeview_effects).append_column("Effects", columns.effect_name);


    treeSel = (*treeview_effects).get_selection();

    treeSel->signal_changed().connect( sigc::mem_fun(*this, &ImotionApp::on_selection_changed));

    m_cameramanager.play_cam(&video);
  }
  else
    {
      //exit(1);
    }
}


ImotionApp::~ImotionApp ()
{
}

/*
void ImotionApp::get_video()
{
  if (video)
    {
      //      printf("xid = %lu\n", gdk_x11_drawable_get_xid( video ));
      //      printf("xid = %lu\n", gdk_x11_drawable_get_xid( GTK_WIDGET( video )->window));
      //      gtk_widget_realize (GTK_WIDGET(main));
      std::cout << gdk_x11_drawable_get_xid( video->get_window()->gobj()) << "\n";

      //      return gdk_x11_drawable_get_xid( video->get_window()->gobj());




    }
}
*/


/*
void ImotionApp::set_video(GstElement *sink)
{
  // window.signal_connect('expose-event') { @videosink.xwindow_id = window.window.xid  }

  sink2 = sink;
  gui_glade_xml->get_widget("drawingarea_video", video);
  video->signal_expose_event().connect( sigc::mem_fun(*this, &ImotionApp::on_expose_event) );
}

bool ImotionApp::on_expose_event(GdkEventExpose* event)
{

  //  sink2.xwindow_id = video.window.xid
  //  gst_x_overlay_set_xwindow_id (GST_X_OVERLAY (sink2), GDK_WINDOW_XID(GTK_WIDGET( video )->window));

  //gdk_x11_drawable_get_xid (video->gobj());

  //  gdk_x11_drawable_get_xid (video);


  //  gdk_x11_drawable_get_xid( GTK_WIDGET( video )->window );

  //  gst_x_overlay_set_xwindow_id (GST_X_OVERLAY (GST_MESSAGE_SRC (sink2)), gdk_x11_drawable_get_xid( GTK_WIDGET( video )->window ));



  //        GTK_WIDGET( video )->allocation.width,

  //  get_window();
  //Glib::RefPtr<Gdk::Window> window = get_window();


  //  printf("prot : %d\n", video->window.xid);
  return false;
}
*/

void
ImotionApp::on_quit_clicked ()
{
  main->hide();
}


void
ImotionApp::on_about_clicked ()
{
  gui_glade_xml->get_widget("aboutdialog", about_dialog);
  about_dialog->show();
}


void
ImotionApp::on_selection_changed ()
{
  m_cameramanager.switch_effect(treeSel->get_selected()->get_value(columns.effect_name).data());
}


void
ImotionApp::on_stop_clicked ()
{
  m_cameramanager.stop_cam();
}
