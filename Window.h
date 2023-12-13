#ifndef SAPER_WINDOW_H
#define SAPER_WINDOW_H

#include "gtkmm.h"

class Window : public Gtk::Window {
private:
    Gtk::Box all_box;
    Gtk::ButtonBox box;
    Gtk::Button no_bomb;
    Gtk::Button bomb;
    Gtk::Button new_game;
    Gtk::Label flags;
public:
    Window(int, int);

    virtual ~Window();

    void click_bomb();
    void click_no_bomb();
};


#endif //SAPER_WINDOW_H
