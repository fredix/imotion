/*
 *  main
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


int
main (int argc, char **argv)
{
  Gtk::Main kit(argc, argv);
  gst_init (&argc, &argv);

  ImotionApp imotionapp;

  if ( Gtk::Window* main = imotionapp.get_main_window () )
    {
      Gtk::Main::run (*main);
    }
  else
    {
      return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
