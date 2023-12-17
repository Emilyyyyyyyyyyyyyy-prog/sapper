#ifndef SAPER_WINDOW_H
#define SAPER_WINDOW_H

#include "gtkmm.h"

class Window : public Gtk::Window {
private:
    int n, m;
    Gtk::Image smile;
    Gtk::Image im_bomb;
    Gtk::Button set_flag;
    Gtk::Box all_box;
    Gtk::Box box;
    Gtk::ButtonBox box1;
    Gtk::ButtonBox box2;
    Gtk::ButtonBox box3;
    Gtk::ButtonBox box4;
    Gtk::ButtonBox box5;
    Gtk::ButtonBox box6;


    Gtk::Button but11;
    Gtk::Button but12;
    Gtk::Button but13;
    Gtk::Button but14;
    Gtk::Button but15;
    Gtk::Button but16;
    Gtk::Button but21;
    Gtk::Button but22;
    Gtk::Button but23;
    Gtk::Button but24;
    Gtk::Button but25;
    Gtk::Button but26;
    Gtk::Button but31;
    Gtk::Button but32;
    Gtk::Button but33;
    Gtk::Button but34;
    Gtk::Button but35;
    Gtk::Button but36;
    Gtk::Button but41;
    Gtk::Button but42;
    Gtk::Button but43;
    Gtk::Button but44;
    Gtk::Button but45;
    Gtk::Button but46;
    Gtk::Button but51;
    Gtk::Button but52;
    Gtk::Button but53;
    Gtk::Button but54;
    Gtk::Button but55;
    Gtk::Button but56;
    Gtk::Button but61;
    Gtk::Button but62;
    Gtk::Button but63;
    Gtk::Button but64;
    Gtk::Button but65;
    Gtk::Button but66;

    Gtk::Button new_game;
    Gtk::Label label_flags;
    Gtk::Label count_flags;
    Gtk::Label label_win;

public:
    Window(int, int);

    virtual ~Window();

//    void start_new_game();

    bool is_win();

    void click_flag();

    void clicked11();

    void clicked12();

    void clicked13();

    void clicked14();

    void clicked15();

    void clicked16();

    void clicked21();

    void clicked22();

    void clicked23();

    void clicked24();

    void clicked25();

    void clicked26();

    void clicked31();

    void clicked32();

    void clicked33();

    void clicked34();

    void clicked35();

    void clicked36();

    void clicked41();

    void clicked42();

    void clicked43();

    void clicked44();

    void clicked45();

    void clicked46();

    void clicked51();

    void clicked52();

    void clicked53();

    void clicked54();

    void clicked55();

    void clicked56();

    void clicked61();

    void clicked62();

    void clicked63();

    void clicked64();

    void clicked65();

    void clicked66();

};


#endif //SAPER_WINDOW_H
