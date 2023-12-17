#include <bits/stdc++.h>
#include "Window.h"

int random(int x) {
    return rand() % x;
}

std::vector<std::vector<bool>> bombs;
std::vector<std::vector<int>> game_table;
bool click_with_flag = false;
bool win = false;

Window::Window(int n, int m) {
    this->n = n;
    this->m = m;

    for (int i = 0; i < n; i++) {
        std::vector<bool> d_b(m, false);
        std::vector<int> d_t(m, 0);
        bombs.push_back(d_b);
        game_table.push_back(d_t);
    }
    // создание бомб
    int n_bombs = n * m / 3;
    for (int i = 0; i < n_bombs; i++) {
        int x_b = random(n);
        int y_b = random(m);
        while (bombs[x_b][y_b]) {
            x_b = random(n);
            y_b = random(m);
        }
        bombs[x_b][y_b] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i - 1 >= 0 and bombs[i - 1][j]) game_table[i][j]++;
            if (i - 1 >= 0 and j - 1 >= 0 and bombs[i - 1][j - 1]) game_table[i][j]++;
            if (i - 1 >= 0 and j + 1 < m and bombs[i - 1][j + 1]) game_table[i][j]++;
            if (i + 1 < n and bombs[i + 1][j]) game_table[i][j]++;
            if (i + 1 < n and j - 1 >= 0 and bombs[i + 1][j - 1]) game_table[i][j]++;
            if (i + 1 < n and j + 1 < m and bombs[i + 1][j + 1]) game_table[i][j]++;
            if (j - 1 >= 0 and bombs[i][j - 1]) game_table[i][j]++;
            if (j + 1 < m and bombs[i][j + 1]) game_table[i][j]++;
        }
    }

    this->set_border_width(5);
    this->all_box = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    this->all_box.set_valign(Gtk::ALIGN_CENTER);

    this->box = Gtk::Box(Gtk::ORIENTATION_HORIZONTAL);
    this->box.set_valign(Gtk::ALIGN_CENTER);

    this->label_flags = Gtk::Label();
    label_flags.set_label("Flags left: ");
    this->label_flags.show();
    this->box.add(this->label_flags);

    this->count_flags = Gtk::Label();
    count_flags.set_label(std::to_string(n_bombs));
    this->count_flags.show();
    this->box.add(this->count_flags);

    this->set_flag = Gtk::Button();
    set_flag.set_size_request(50, 50);
    set_flag.set_border_width(5);
    set_flag.set_label("set_flag");
    this->box.add(this->set_flag);
    this->set_flag.signal_clicked().connect(sigc::mem_fun(*this, &Window::click_flag));
    this->set_flag.show();

    this->label_win = Gtk::Label();
    label_win.set_label("You win!");
    this->box.add(this->label_win);

//    this->new_game = Gtk::Button();
//    new_game.set_size_request(50, 50);
//    new_game.set_border_width(5);
//    this->smile = Gtk::Image();
//    this->smile.set_from_resource("smile.png");
//    this->smile.show();
//    new_game.set_image(this->smile);
//    this->box.add(this->smile);
//    new_game.signal_clicked().connect(sigc::mem_fun(*this, &Window::start_new_game));
//    this->new_game.show();


    this->box.show();
    this->all_box.add(this->box);


//    for (int i = 0; i < n; i++) {
//        this->box = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
//        this->box.set_valign(Gtk::ALIGN_CENTER);
//
//        for (int j = 0; j < m; j++) {
//            if (bombs[i][j]) {
//                this->bomb = Gtk::Button("b");
//                bomb.set_size_request(40, 40);
//                bomb.set_border_width(5);
//                this->box.add(this->bomb);
//                this->bomb.show();
//                this->bomb.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Window::click_bomb), i, j));
//
//            } else {
//                this->no_bomb = Gtk::Button("n");
//                no_bomb.set_size_request(40, 40);
//                no_bomb.set_border_width(5);
//                this->box.add(this->no_bomb);
//                this->no_bomb.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &Window::click_no_bomb), i, j));
//
//                this->no_bomb.show();
//            }
//        }
//        this->box.show();
//        this->all_box.add(this->box);
//    }
    this->box1 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box1.set_valign(Gtk::ALIGN_CENTER);


//    this->im_bomb = Gtk::Image("bomb.png");

    this->but11 = Gtk::Button(" ");
    but11.set_size_request(40, 40);
    but11.set_border_width(5);
    this->box1.add(this->but11);
    this->but11.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked11));
    this->but11.show();

    this->but12 = Gtk::Button(" ");
    but12.set_size_request(40, 40);
    but12.set_border_width(5);
    this->box1.add(this->but12);
    this->but12.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked12));
    this->but12.show();

    this->but13 = Gtk::Button(" ");
    but13.set_size_request(40, 40);
    but13.set_border_width(5);
    this->box1.add(this->but13);
    this->but13.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked13));
    this->but13.show();

    this->but14 = Gtk::Button(" ");
    but14.set_size_request(40, 40);
    but14.set_border_width(5);
    this->box1.add(this->but14);
    this->but14.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked14));
    this->but14.show();

    this->but15 = Gtk::Button(" ");
    but15.set_size_request(40, 40);
    but15.set_border_width(5);
    this->box1.add(this->but15);
    this->but15.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked15));
    this->but15.show();

    this->but16 = Gtk::Button(" ");
    but16.set_size_request(40, 40);
    but16.set_border_width(5);
    this->box1.add(this->but16);
    this->but16.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked16));
    this->but16.show();

    this->box1.show();
    this->all_box.add(this->box1);

    this->box2 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box2.set_valign(Gtk::ALIGN_CENTER);

    this->but21 = Gtk::Button(" ");
    but21.set_size_request(40, 40);
    but21.set_border_width(5);
    this->box2.add(this->but21);
    this->but21.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked21));
    this->but21.show();

    this->but22 = Gtk::Button(" ");
    but22.set_size_request(40, 40);
    but22.set_border_width(5);
    this->box2.add(this->but22);
    this->but22.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked22));
    this->but22.show();

    this->but23 = Gtk::Button(" ");
    but23.set_size_request(40, 40);
    but23.set_border_width(5);
    this->box2.add(this->but23);
    this->but23.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked23));
    this->but23.show();

    this->but24 = Gtk::Button(" ");
    but24.set_size_request(40, 40);
    but24.set_border_width(5);
    this->box2.add(this->but24);
    this->but24.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked24));
    this->but24.show();

    this->but25 = Gtk::Button(" ");
    but25.set_size_request(40, 40);
    but25.set_border_width(5);
    this->box2.add(this->but25);
    this->but25.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked25));
    this->but25.show();

    this->but26 = Gtk::Button(" ");
    but26.set_size_request(40, 40);
    but26.set_border_width(5);
    this->box2.add(this->but26);
    this->but26.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked26));
    this->but26.show();

    this->box2.show();
    this->all_box.add(this->box2);

    this->box3 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box3.set_valign(Gtk::ALIGN_CENTER);

    this->but31 = Gtk::Button(" ");
    but31.set_size_request(40, 40);
    but31.set_border_width(5);
    this->box3.add(this->but31);
    this->but31.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked31));
    this->but31.show();

    this->but32 = Gtk::Button(" ");
    but32.set_size_request(40, 40);
    but32.set_border_width(5);
    this->box3.add(this->but32);
    this->but32.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked32));
    this->but32.show();

    this->but33 = Gtk::Button(" ");
    but33.set_size_request(40, 40);
    but33.set_border_width(5);
    this->box3.add(this->but33);
    this->but33.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked33));
    this->but33.show();

    this->but34 = Gtk::Button(" ");
    but34.set_size_request(40, 40);
    but34.set_border_width(5);
    this->box3.add(this->but34);
    this->but34.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked34));
    this->but34.show();

    this->but35 = Gtk::Button(" ");
    but35.set_size_request(40, 40);
    but35.set_border_width(5);
    this->box3.add(this->but35);
    this->but35.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked35));
    this->but35.show();

    this->but36 = Gtk::Button(" ");
    but36.set_size_request(40, 40);
    but36.set_border_width(5);
    this->box3.add(this->but36);
    this->but36.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked36));
    this->but36.show();

    this->box3.show();
    this->all_box.add(this->box3);

    this->box4 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box4.set_valign(Gtk::ALIGN_CENTER);

    this->but41 = Gtk::Button(" ");
    but41.set_size_request(40, 40);
    but41.set_border_width(5);
    this->box4.add(this->but41);
    this->but41.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked41));
    this->but41.show();

    this->but42 = Gtk::Button(" ");
    but42.set_size_request(40, 40);
    but42.set_border_width(5);
    this->box4.add(this->but42);
    this->but42.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked42));
    this->but42.show();

    this->but43 = Gtk::Button(" ");
    but43.set_size_request(40, 40);
    but43.set_border_width(5);
    this->box4.add(this->but43);
    this->but43.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked43));
    this->but43.show();

    this->but44 = Gtk::Button(" ");
    but44.set_size_request(40, 40);
    but44.set_border_width(5);
    this->box4.add(this->but44);
    this->but44.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked44));
    this->but44.show();

    this->but45 = Gtk::Button(" ");
    but45.set_size_request(40, 40);
    but45.set_border_width(5);
    this->box4.add(this->but45);
    this->but45.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked45));
    this->but45.show();

    this->but46 = Gtk::Button(" ");
    but46.set_size_request(40, 40);
    but46.set_border_width(5);
    this->box4.add(this->but46);
    this->but46.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked46));
    this->but46.show();

    this->box4.show();
    this->all_box.add(this->box4);

    this->box5 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box5.set_valign(Gtk::ALIGN_CENTER);

    this->but51 = Gtk::Button(" ");
    but51.set_size_request(40, 40);
    but51.set_border_width(5);
    this->box5.add(this->but51);
    this->but51.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked51));
    this->but51.show();

    this->but52 = Gtk::Button(" ");
    but52.set_size_request(40, 40);
    but52.set_border_width(5);
    this->box5.add(this->but52);
    this->but52.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked52));
    this->but52.show();

    this->but53 = Gtk::Button(" ");
    but53.set_size_request(40, 40);
    but53.set_border_width(5);
    this->box5.add(this->but53);
    this->but53.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked53));
    this->but53.show();

    this->but54 = Gtk::Button(" ");
    but54.set_size_request(40, 40);
    but54.set_border_width(5);
    this->box5.add(this->but54);
    this->but54.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked54));
    this->but54.show();

    this->but55 = Gtk::Button(" ");
    but55.set_size_request(40, 40);
    but55.set_border_width(5);
    this->box5.add(this->but55);
    this->but55.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked55));
    this->but55.show();

    this->but56 = Gtk::Button(" ");
    but56.set_size_request(40, 40);
    but56.set_border_width(5);
    this->box5.add(this->but56);
    this->but56.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked56));
    this->but56.show();

    this->box5.show();
    this->all_box.add(this->box5);

    this->box6 = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
    this->box6.set_valign(Gtk::ALIGN_CENTER);

    this->but61 = Gtk::Button(" ");
    but61.set_size_request(40, 40);
    but61.set_border_width(5);
    this->box6.add(this->but61);
    this->but61.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked61));
    this->but61.show();

    this->but62 = Gtk::Button(" ");
    but62.set_size_request(40, 40);
    but62.set_border_width(5);
    this->box6.add(this->but62);
    this->but62.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked62));
    this->but62.show();

    this->but63 = Gtk::Button(" ");
    but63.set_size_request(40, 40);
    but63.set_border_width(5);
    this->box6.add(this->but63);
    this->but63.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked63));
    this->but63.show();

    this->but64 = Gtk::Button(" ");
    but64.set_size_request(40, 40);
    but64.set_border_width(5);
    this->box6.add(this->but64);
    this->but64.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked64));
    this->but64.show();

    this->but65 = Gtk::Button(" ");
    but65.set_size_request(40, 40);
    but65.set_border_width(5);
    this->box6.add(this->but65);
    this->but65.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked65));
    this->but65.show();

    this->but66 = Gtk::Button(" ");
    but66.set_size_request(40, 40);
    but66.set_border_width(5);
    this->box6.add(this->but66);
    this->but66.signal_clicked().connect(sigc::mem_fun(*this, &Window::clicked66));
    this->but66.show();

    this->box6.show();
    this->all_box.add(this->box6);

    this->add(this->all_box);
    this->all_box.show();
}

//void Window::start_new_game() {
//
//}

bool Window::is_win() {
    if (this->but11.get_label() != " " and this->but12.get_label() != " " and this->but13.get_label() != " " and
        this->but14.get_label() != " " and this->but15.get_label() != " " and this->but16.get_label() != " " and
        this->but21.get_label() != " " and this->but22.get_label() != " " and this->but23.get_label() != " " and
        this->but24.get_label() != " " and this->but25.get_label() != " " and this->but26.get_label() != " " and
        this->but31.get_label() != " " and this->but32.get_label() != " " and this->but33.get_label() != " " and
        this->but34.get_label() != " " and this->but35.get_label() != " " and this->but36.get_label() != " " and
        this->but41.get_label() != " " and this->but42.get_label() != " " and this->but43.get_label() != " " and
        this->but44.get_label() != " " and this->but45.get_label() != " " and this->but46.get_label() != " " and
        this->but51.get_label() != " " and this->but52.get_label() != " " and this->but53.get_label() != " " and
        this->but54.get_label() != " " and this->but55.get_label() != " " and this->but56.get_label() != " " and
        this->but61.get_label() != " " and this->but62.get_label() != " " and this->but63.get_label() != " " and
        this->but64.get_label() != " " and this->but65.get_label() != " " and this->but66.get_label() != " ") {
        win = true;
        this->label_win.show();
        return true;
    }
    return false;
}

void Window::click_flag() {
    if (click_with_flag) {
        click_with_flag = false;
        this->set_flag.set_label("set flag");
    } else {
        click_with_flag = true;
        this->set_flag.set_label("delete flag");
    }
}

void Window::clicked11() {
    if (click_with_flag and this->but11.get_label() == "F") {
        this->but11.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but11.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but11.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][0] and this->but11.get_label() == " ") {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but11.set_label(std::to_string(game_table[0][0]));
        if (this->is_win()) return;
        if (!bombs[0][1] and this->but12.get_label() != "F")
            this->but12.set_label(std::to_string(game_table[0][1]));
        if (!bombs[1][0] and this->but21.get_label() != "F") this->but21.set_label(std::to_string(game_table[1][0]));
    }
}

void Window::clicked12() {
    if (click_with_flag and this->but12.get_label() == "F") {
        this->but12.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but12.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but12.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but12.set_label(std::to_string(game_table[0][1]));
        if (this->is_win()) return;
        if (!bombs[0][2] and this->but13.get_label() != "F") this->but13.set_label(std::to_string(game_table[0][2]));
        if (!bombs[0][0] and this->but11.get_label() != "F") this->but11.set_label(std::to_string(game_table[0][0]));
        if (!bombs[1][1] and this->but22.get_label() != "F") this->but22.set_label(std::to_string(game_table[1][1]));
    }
}

void Window::clicked13() {
    if (click_with_flag and this->but13.get_label() == "F") {
        this->but13.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but13.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but13.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but13.set_label(std::to_string(game_table[0][2]));
        if (this->is_win()) return;
        if (!bombs[0][1] and this->but12.get_label() != "F") this->but12.set_label(std::to_string(game_table[0][1]));
        if (!bombs[0][3] and this->but14.get_label() != "F") this->but14.set_label(std::to_string(game_table[0][3]));
        if (!bombs[1][2] and this->but23.get_label() != "F") this->but23.set_label(std::to_string(game_table[1][2]));
    }
}

void Window::clicked14() {
    if (click_with_flag and this->but14.get_label() == "F") {
        this->but14.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but14.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but14.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but14.set_label(std::to_string(game_table[0][3]));
        if (this->is_win()) return;
        if (!bombs[0][2] and this->but13.get_label() != "F") this->but13.set_label(std::to_string(game_table[0][2]));
        if (!bombs[0][4] and this->but15.get_label() != "F") this->but15.set_label(std::to_string(game_table[0][4]));
        if (!bombs[1][3] and this->but24.get_label() != "F") this->but24.set_label(std::to_string(game_table[1][3]));
    }
}

void Window::clicked15() {
    if (click_with_flag and this->but15.get_label() == "F") {
        this->but15.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but15.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but15.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but15.set_label(std::to_string(game_table[0][4]));
        if (this->is_win()) return;
        if (!bombs[0][3] and this->but14.get_label() != "F") this->but14.set_label(std::to_string(game_table[0][3]));
        if (!bombs[0][5] and this->but16.get_label() != "F") this->but16.set_label(std::to_string(game_table[0][5]));
        if (!bombs[1][4] and this->but25.get_label() != "F") this->but25.set_label(std::to_string(game_table[1][4]));
    }
}

void Window::clicked16() {
    if (click_with_flag and this->but16.get_label() == "F") {
        this->but16.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but16.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but16.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[0][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but16.set_label(std::to_string(game_table[0][5]));
        if (this->is_win()) return;
        if (!bombs[0][4] and this->but15.get_label() != "F") this->but15.set_label(std::to_string(game_table[0][4]));
        if (!bombs[1][5] and this->but26.get_label() != "F") this->but26.set_label(std::to_string(game_table[1][5]));
    }
}

void Window::clicked21() {
    if (click_with_flag and this->but21.get_label() == "F") {
        this->but21.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but21.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but21.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][0]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but21.set_label(std::to_string(game_table[1][0]));
        if (this->is_win()) return;
        if (!bombs[1][1] and this->but22.get_label() != "F") this->but22.set_label(std::to_string(game_table[1][1]));
        if (!bombs[0][0] and this->but11.get_label() != "F") this->but11.set_label(std::to_string(game_table[0][0]));
        if (!bombs[2][0] and this->but31.get_label() != "F") this->but31.set_label(std::to_string(game_table[2][0]));
    }
}

void Window::clicked22() {
    if (click_with_flag and this->but22.get_label() == "F") {
        this->but22.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but22.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but22.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but22.set_label(std::to_string(game_table[1][1]));
        if (this->is_win()) return;
        if (!bombs[1][0] and this->but21.get_label() != "F") this->but21.set_label(std::to_string(game_table[1][0]));
        if (!bombs[1][2] and this->but23.get_label() != "F") this->but23.set_label(std::to_string(game_table[1][2]));
        if (!bombs[0][1] and this->but12.get_label() != "F") this->but12.set_label(std::to_string(game_table[0][1]));
        if (!bombs[2][1] and this->but32.get_label() != "F") this->but32.set_label(std::to_string(game_table[2][1]));
    }
}

void Window::clicked23() {
    if (click_with_flag and this->but23.get_label() == "F") {
        this->but23.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but23.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but23.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but23.set_label(std::to_string(game_table[1][2]));
        if (this->is_win()) return;
        if (!bombs[1][1] and this->but22.get_label() != "F") this->but22.set_label(std::to_string(game_table[1][1]));
        if (!bombs[1][3] and this->but24.get_label() != "F") this->but24.set_label(std::to_string(game_table[1][3]));
        if (!bombs[2][2] and this->but33.get_label() != "F") this->but33.set_label(std::to_string(game_table[2][2]));
        if (!bombs[0][2] and this->but13.get_label() != "F") this->but13.set_label(std::to_string(game_table[0][2]));
    }
}

void Window::clicked24() {
    if (click_with_flag and this->but24.get_label() == "F") {
        this->but24.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but24.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but24.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but24.set_label(std::to_string(game_table[1][3]));
        if (this->is_win()) return;
        if (!bombs[1][2] and this->but23.get_label() != "F") this->but23.set_label(std::to_string(game_table[1][2]));
        if (!bombs[1][4] and this->but25.get_label() != "F") this->but25.set_label(std::to_string(game_table[1][4]));
        if (!bombs[2][3] and this->but34.get_label() != "F") this->but34.set_label(std::to_string(game_table[2][3]));
        if (!bombs[0][3] and this->but14.get_label() != "F") this->but14.set_label(std::to_string(game_table[0][3]));
    }
}

void Window::clicked25() {
    if (win) return;
    if (click_with_flag and this->but25.get_label() == "F") {
        this->but25.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but25.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but25.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but25.set_label(std::to_string(game_table[1][4]));
        if (this->is_win()) return;
        if (!bombs[1][3] and this->but24.get_label() != "F") this->but24.set_label(std::to_string(game_table[1][3]));
        if (!bombs[1][5] and this->but26.get_label() != "F") this->but26.set_label(std::to_string(game_table[1][5]));
        if (!bombs[2][4] and this->but35.get_label() != "F") this->but35.set_label(std::to_string(game_table[2][4]));
        if (!bombs[0][4] and this->but15.get_label() != "F") this->but15.set_label(std::to_string(game_table[0][4]));
    }
}

void Window::clicked26() {
    if (win) return;
    if (click_with_flag and this->but26.get_label() == "F") {
        this->but26.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but26.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but26.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[1][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but26.set_label(std::to_string(game_table[1][5]));
        if (this->is_win()) return;
        if (!bombs[2][5] and this->but36.get_label() != "F") this->but36.set_label(std::to_string(game_table[2][5]));
        if (!bombs[0][5] and this->but16.get_label() != "F") this->but16.set_label(std::to_string(game_table[0][5]));
        if (!bombs[1][4] and this->but25.get_label() != "F") this->but25.set_label(std::to_string(game_table[1][4]));
    }
}

void Window::clicked31() {
    if (win) return;
    if (click_with_flag and this->but31.get_label() == "F") {
        this->but31.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but31.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but31.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][0]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but31.set_label(std::to_string(game_table[2][0]));
        if (this->is_win()) return;
        if (!bombs[2][1] and this->but32.get_label() != "F") this->but32.set_label(std::to_string(game_table[2][1]));
        if (!bombs[3][0] and this->but41.get_label() != "F") this->but41.set_label(std::to_string(game_table[3][0]));
        if (!bombs[1][0] and this->but21.get_label() != "F") this->but21.set_label(std::to_string(game_table[1][0]));
    }
}

void Window::clicked32() {
    if (win) return;
    if (click_with_flag and this->but32.get_label() == "F") {
        this->but32.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but32.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but32.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but32.set_label(std::to_string(game_table[2][1]));
        if (this->is_win()) return;
        if (!bombs[2][0] and this->but31.get_label() != "F") this->but31.set_label(std::to_string(game_table[2][0]));
        if (!bombs[2][2] and this->but33.get_label() != "F") this->but33.set_label(std::to_string(game_table[2][2]));
        if (!bombs[3][1] and this->but42.get_label() != "F") this->but42.set_label(std::to_string(game_table[3][1]));
        if (!bombs[1][1] and this->but22.get_label() != "F") this->but22.set_label(std::to_string(game_table[1][1]));
    }
}

void Window::clicked33() {
    if (win) return;
    if (click_with_flag and this->but33.get_label() == "F") {
        this->but33.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but33.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but33.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but33.set_label(std::to_string(game_table[2][2]));
        if (this->is_win()) return;
        if (!bombs[2][3] and this->but34.get_label() != "F") this->but34.set_label(std::to_string(game_table[2][3]));
        if (!bombs[2][1] and this->but32.get_label() != "F") this->but32.set_label(std::to_string(game_table[2][1]));
        if (!bombs[3][2] and this->but43.get_label() != "F") this->but43.set_label(std::to_string(game_table[3][2]));
        if (!bombs[1][2] and this->but23.get_label() != "F") this->but23.set_label(std::to_string(game_table[1][2]));
    }
}

void Window::clicked34() {
    if (win) return;
    if (click_with_flag and this->but34.get_label() == "F") {
        this->but34.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but34.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but34.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but34.set_label(std::to_string(game_table[2][3]));
        if (this->is_win()) return;
        if (!bombs[2][4] and this->but35.get_label() != "F") this->but35.set_label(std::to_string(game_table[2][4]));
        if (!bombs[2][2] and this->but33.get_label() != "F") this->but33.set_label(std::to_string(game_table[2][2]));
        if (!bombs[1][3] and this->but24.get_label() != "F") this->but24.set_label(std::to_string(game_table[1][3]));
        if (!bombs[3][3] and this->but44.get_label() != "F") this->but44.set_label(std::to_string(game_table[3][3]));
    }
}

void Window::clicked35() {
    if (win) return;
    if (click_with_flag and this->but35.get_label() == "F") {
        this->but35.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but35.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but35.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but35.set_label(std::to_string(game_table[2][4]));
        if (this->is_win()) return;
        if (!bombs[2][5] and this->but36.get_label() != "F") this->but36.set_label(std::to_string(game_table[2][5]));
        if (!bombs[2][3] and this->but34.get_label() != "F") this->but34.set_label(std::to_string(game_table[2][3]));
        if (!bombs[1][4] and this->but25.get_label() != "F") this->but25.set_label(std::to_string(game_table[1][4]));
        if (!bombs[3][4] and this->but45.get_label() != "F") this->but45.set_label(std::to_string(game_table[3][4]));
    }
}

void Window::clicked36() {
    if (win) return;
    if (click_with_flag and this->but36.get_label() == "F") {
        this->but36.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but36.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but36.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[2][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but36.set_label(std::to_string(game_table[2][5]));
        if (this->is_win()) return;
        if (!bombs[2][4] and this->but35.get_label() != "F") this->but35.set_label(std::to_string(game_table[2][4]));
        if (!bombs[3][5] and this->but46.get_label() != "F") this->but46.set_label(std::to_string(game_table[3][5]));
        if (!bombs[1][5] and this->but26.get_label() != "F") this->but26.set_label(std::to_string(game_table[1][5]));
    }
}

void Window::clicked41() {
    if (win) return;
    if (click_with_flag and this->but41.get_label() == "F") {
        this->but41.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but41.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but41.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][0]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but41.set_label(std::to_string(game_table[3][0]));
        if (this->is_win()) return;
        if (!bombs[3][1] and this->but42.get_label() != "F") this->but42.set_label(std::to_string(game_table[3][1]));
        if (!bombs[2][0] and this->but31.get_label() != "F") this->but31.set_label(std::to_string(game_table[2][0]));
        if (!bombs[4][0] and this->but51.get_label() != "F") this->but51.set_label(std::to_string(game_table[4][0]));
    }
}

void Window::clicked42() {
    if (win) return;
    if (click_with_flag and this->but42.get_label() == "F") {
        this->but42.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but42.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but42.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but42.set_label(std::to_string(game_table[3][1]));
        if (this->is_win()) return;
        if (!bombs[4][1] and this->but52.get_label() != "F") this->but52.set_label(std::to_string(game_table[4][1]));
        if (!bombs[2][1] and this->but32.get_label() != "F") this->but32.set_label(std::to_string(game_table[2][1]));
        if (!bombs[3][2] and this->but43.get_label() != "F") this->but43.set_label(std::to_string(game_table[3][2]));
        if (!bombs[3][0] and this->but41.get_label() != "F") this->but41.set_label(std::to_string(game_table[3][0]));
    }
}

void Window::clicked43() {
    if (win) return;
    if (click_with_flag and this->but43.get_label() == "F") {
        this->but43.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but43.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but43.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but43.set_label(std::to_string(game_table[3][2]));
        if (this->is_win()) return;
        if (!bombs[3][1] and this->but42.get_label() != "F") this->but42.set_label(std::to_string(game_table[3][1]));
        if (!bombs[3][3] and this->but44.get_label() != "F") this->but44.set_label(std::to_string(game_table[3][3]));
        if (!bombs[4][2] and this->but53.get_label() != "F") this->but53.set_label(std::to_string(game_table[4][2]));
        if (!bombs[2][2] and this->but33.get_label() != "F") this->but33.set_label(std::to_string(game_table[2][2]));
    }
}

void Window::clicked44() {
    if (win) return;
    if (click_with_flag and this->but44.get_label() == "F") {
        this->but44.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but44.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but44.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but44.set_label(std::to_string(game_table[3][3]));
        if (this->is_win()) return;
        if (!bombs[3][4] and this->but45.get_label() != "F") this->but45.set_label(std::to_string(game_table[3][4]));
        if (!bombs[3][2] and this->but43.get_label() != "F") this->but43.set_label(std::to_string(game_table[3][2]));
        if (!bombs[4][3] and this->but54.get_label() != "F") this->but54.set_label(std::to_string(game_table[4][3]));
        if (!bombs[2][3] and this->but34.get_label() != "F") this->but34.set_label(std::to_string(game_table[2][3]));
    }
}

void Window::clicked45() {
    if (win) return;
    if (click_with_flag and this->but45.get_label() == "F") {
        this->but45.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but45.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but45.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but45.set_label(std::to_string(game_table[3][4]));
        if (this->is_win()) return;
        if (!bombs[3][3] and this->but44.get_label() != "F") this->but44.set_label(std::to_string(game_table[3][3]));
        if (!bombs[3][5] and this->but46.get_label() != "F") this->but46.set_label(std::to_string(game_table[3][5]));
        if (!bombs[4][4] and this->but55.get_label() != "F") this->but55.set_label(std::to_string(game_table[4][4]));
        if (!bombs[2][4] and this->but35.get_label() != "F") this->but35.set_label(std::to_string(game_table[2][4]));

    }
}

void Window::clicked46() {
    if (win) return;
    if (click_with_flag and this->but46.get_label() == "F") {
        this->but46.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but46.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but46.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[3][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but46.set_label(std::to_string(game_table[3][5]));
        if (this->is_win()) return;
        if (!bombs[3][4] and this->but45.get_label() != "F") this->but45.set_label(std::to_string(game_table[3][4]));
        if (!bombs[2][5] and this->but36.get_label() != "F") this->but36.set_label(std::to_string(game_table[2][5]));
        if (!bombs[4][5] and this->but56.get_label() != "F") this->but56.set_label(std::to_string(game_table[4][5]));
    }
}

void Window::clicked51() {
    if (win) return;
    if (click_with_flag and this->but51.get_label() == "F") {
        this->but51.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but51.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but51.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][0]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but51.set_label(std::to_string(game_table[4][0]));
        if (this->is_win()) return;
        if (!bombs[4][1] and this->but52.get_label() != "F") this->but52.set_label(std::to_string(game_table[4][1]));
        if (!bombs[3][0] and this->but41.get_label() != "F") this->but41.set_label(std::to_string(game_table[3][0]));
        if (!bombs[5][0] and this->but61.get_label() != "F") this->but61.set_label(std::to_string(game_table[5][0]));
    }
}

void Window::clicked52() {
    if (win) return;
    if (click_with_flag and this->but52.get_label() == "F") {
        this->but52.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but52.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but52.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but52.set_label(std::to_string(game_table[4][1]));
        if (this->is_win()) return;
        if (!bombs[4][0] and this->but51.get_label() != "F") this->but51.set_label(std::to_string(game_table[4][0]));
        if (!bombs[4][2] and this->but53.get_label() != "F") this->but53.set_label(std::to_string(game_table[4][2]));
        if (!bombs[5][1] and this->but62.get_label() != "F") this->but62.set_label(std::to_string(game_table[5][1]));
        if (!bombs[3][1] and this->but42.get_label() != "F") this->but42.set_label(std::to_string(game_table[3][1]));

    }
}

void Window::clicked53() {
    if (win) return;
    if (click_with_flag and this->but53.get_label() == "F") {
        this->but53.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but53.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but53.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but53.set_label(std::to_string(game_table[4][2]));
        if (this->is_win()) return;
        if (!bombs[4][1] and this->but52.get_label() != "F") this->but52.set_label(std::to_string(game_table[4][1]));
        if (!bombs[4][3] and this->but54.get_label() != "F") this->but54.set_label(std::to_string(game_table[4][3]));
        if (!bombs[3][2] and this->but43.get_label() != "F") this->but43.set_label(std::to_string(game_table[3][2]));
        if (!bombs[5][2] and this->but63.get_label() != "F") this->but63.set_label(std::to_string(game_table[5][2]));
    }
}

void Window::clicked54() {
    if (win) return;
    if (click_with_flag and this->but54.get_label() == "F") {
        this->but54.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but54.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but54.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but54.set_label(std::to_string(game_table[4][3]));
        if (this->is_win()) return;
        if (!bombs[4][4] and this->but55.get_label() != "F") this->but55.set_label(std::to_string(game_table[5][4]));
        if (!bombs[4][2] and this->but53.get_label() != "F") this->but53.set_label(std::to_string(game_table[4][5]));
        if (!bombs[5][3] and this->but64.get_label() != "F") this->but64.set_label(std::to_string(game_table[3][4]));
        if (!bombs[3][3] and this->but44.get_label() != "F") this->but44.set_label(std::to_string(game_table[4][3]));
    }
}

void Window::clicked55() {
    if (win) return;
    if (click_with_flag and this->but55.get_label() == "F") {
        this->but55.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but55.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but55.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but55.set_label(std::to_string(game_table[4][4]));
        if (this->is_win()) return;
        if (!bombs[5][4] and this->but65.get_label() != "F") this->but65.set_label(std::to_string(game_table[5][4]));
        if (!bombs[4][5] and this->but56.get_label() != "F") this->but56.set_label(std::to_string(game_table[4][5]));
        if (!bombs[3][4] and this->but45.get_label() != "F") this->but45.set_label(std::to_string(game_table[3][4]));
        if (!bombs[4][3] and this->but54.get_label() != "F") this->but54.set_label(std::to_string(game_table[4][3]));
    }
}

void Window::clicked56() {
    if (win) return;
    if (click_with_flag and this->but56.get_label() == "F") {
        this->but56.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but56.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but56.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[4][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but56.set_label(std::to_string(game_table[4][5]));
        if (this->is_win()) return;
        if (!bombs[5][5] and this->but66.get_label() != "F") this->but66.set_label(std::to_string(game_table[5][5]));
        if (!bombs[4][4] and this->but55.get_label() != "F") this->but55.set_label(std::to_string(game_table[4][4]));
        if (!bombs[3][5] and this->but46.get_label() != "F") this->but46.set_label(std::to_string(game_table[3][5]));
    }
}

void Window::clicked61() {
    if (win) return;
    if (click_with_flag and this->but61.get_label() == "F") {
        this->but61.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but61.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but61.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][0]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but61.set_label(std::to_string(game_table[5][0]));
        if (this->is_win()) return;
        if (!bombs[4][0] and this->but51.get_label() != "F") this->but51.set_label(std::to_string(game_table[4][0]));
        if (!bombs[5][1] and this->but62.get_label() != "F") this->but62.set_label(std::to_string(game_table[5][1]));
    }
}

void Window::clicked62() {
    if (win) return;
    if (click_with_flag and this->but62.get_label() == "F") {
        this->but62.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but62.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but62.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][1]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but62.set_label(std::to_string(game_table[5][1]));
        if (this->is_win()) return;
        if (!bombs[5][0] and this->but61.get_label() != "F") this->but61.set_label(std::to_string(game_table[5][0]));
        if (!bombs[4][1] and this->but52.get_label() != "F") this->but52.set_label(std::to_string(game_table[4][1]));
        if (!bombs[5][2] and this->but63.get_label() != "F") this->but63.set_label(std::to_string(game_table[5][2]));
    }
}

void Window::clicked63() {
    if (win) return;
    if (click_with_flag and this->but63.get_label() == "F") {
        this->but63.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but63.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but63.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][2]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but63.set_label(std::to_string(game_table[5][2]));
        if (this->is_win()) return;
        if (!bombs[5][3] and this->but64.get_label() != "F") this->but64.set_label(std::to_string(game_table[5][3]));
        if (!bombs[4][2] and this->but53.get_label() != "F") this->but53.set_label(std::to_string(game_table[4][2]));
        if (!bombs[5][1] and this->but62.get_label() != "F") this->but62.set_label(std::to_string(game_table[5][1]));
    }
}

void Window::clicked64() {
    if (win) return;
    if (click_with_flag and this->but64.get_label() == "F") {
        this->but64.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but64.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but64.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][3]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but64.set_label(std::to_string(game_table[5][3]));
        if (this->is_win()) return;
        if (!bombs[5][4] and this->but65.get_label() != "F") this->but65.set_label(std::to_string(game_table[5][4]));
        if (!bombs[4][3] and this->but54.get_label() != "F") this->but54.set_label(std::to_string(game_table[4][3]));
        if (!bombs[5][2] and this->but63.get_label() != "F") this->but63.set_label(std::to_string(game_table[5][2]));
    }
}

void Window::clicked65() {
    if (win) return;
    if (click_with_flag and this->but65.get_label() == "F") {
        this->but65.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but65.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but65.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][4]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but65.set_label(std::to_string(game_table[5][4]));
        if (this->is_win()) return;
        if (!bombs[5][5] and this->but66.get_label() != "F") this->but66.set_label(std::to_string(game_table[5][5]));
        if (!bombs[4][4] and this->but55.get_label() != "F") this->but55.set_label(std::to_string(game_table[4][4]));
        if (!bombs[5][3] and this->but64.get_label() != "F") this->but64.set_label(std::to_string(game_table[5][3]));
    }
}

void Window::clicked66() {
    if (win) return;
    if (click_with_flag and this->but66.get_label() == "F") {
        this->but66.set_label(" ");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) + 1));
        return;
    }
    if (this->but66.get_label() == "F") return;
    if (click_with_flag and std::stoi(this->count_flags.get_label()) > 0) {
        this->but66.set_label("F");
        this->count_flags.set_label(std::to_string(std::stoi(this->count_flags.get_label()) - 1));
        return;
    }
    if (bombs[5][5]) {
        std::cout << "boom!";
        Gtk::Main::quit();
    } else {
        this->but66.set_label(std::to_string(game_table[5][5]));
        if (this->is_win()) return;
        if (!bombs[5][4] and this->but65.get_label() != "F") this->but65.set_label(std::to_string(game_table[5][4]));
        if (!bombs[4][5] and this->but56.get_label() != "F") this->but56.set_label(std::to_string(game_table[4][5]));
    }
}

Window::~Window() = default;
