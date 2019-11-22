/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <gtkmm.h>
#include "examplewindow.h"
#include <iostream>

Gtk::ApplicationWindow* w = nullptr;

int main(int argc, char *argv[]){
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  auto refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("src/interfaces/other.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  refBuilder->get_widget("GtkApplicationWindow", w);
  //Shows the window and returns when it is closed.
  return app->run(*w);
}