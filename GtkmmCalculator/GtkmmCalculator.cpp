#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm/cssprovider.h>
#include <gtkmm/builder.h>
#include "MainWindow.h"

using namespace Gtk;

int main(int argc, char* argv[])
{
    auto app = Application::create(argc, argv, "org.gtkmm.example");
    Glib::RefPtr<Gtk::CssProvider> cssProvider = Gtk::CssProvider::create();
    cssProvider->load_from_data("button {background-color: #2a1344; border-radius: 4px; margin: 4px 4px;} label{ font-size: 20px; }");
    Glib::RefPtr<Gtk::StyleContext> styleContext = Gtk::StyleContext::create();

    //get default screen
    Glib::RefPtr<Gdk::Screen> screen = Gdk::Screen::get_default();
    //add provider for screen in all application
    styleContext->add_provider_for_screen(screen, cssProvider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    MainWindow mainWin;

    return app->run(mainWin);
}