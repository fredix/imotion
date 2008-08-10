/*
 *  callback
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

#include "ui.h"
#include "callback.h"

/*
void on_togglebutton_toggled (GtkWidget *toggle_button, gpointer paned) {
  if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(toggle_button))) {

    ImotionWidget.iPanedPosition = gtk_paned_get_position (GTK_PANED(paned));
    ImotionWidget.iPanedShellPosition = gtk_paned_get_position (GTK_PANED(ImotionWidget.vpaned_shell));

    gtk_paned_set_position (GTK_PANED (paned), 10000);
    gtk_paned_set_position (GTK_PANED (ImotionWidget.vpaned_shell), 10000);

  }
  else {
    if (!ImotionWidget.iPanedPosition) ImotionWidget.iPanedPosition = 200;

    gtk_paned_set_position (GTK_PANED (paned), ImotionWidget.iPanedPosition);
    gtk_paned_set_position (GTK_PANED (ImotionWidget.vpaned_shell), ImotionWidget.iPanedShellPosition);
  }
}

*/


void on_quit_clicked()
{
  if(pMain)
    pMain->hide(); //hide() will cause main::run() to end.
}


void on_about_clicked()
{
  Gtk::AboutDialog* pAbout = 0;
  gui_glade_xml->get_widget("aboutdialog", pAbout);
  pAbout->show();
}

void on_toggletoolbutton_chat_toggled() {

}


void on_toolbutton_stop_clicked() {
}
