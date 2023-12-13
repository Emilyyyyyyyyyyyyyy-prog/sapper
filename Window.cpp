#include <bits/stdc++.h>
#include "Window.h"

int random(int x) {
    return rand() % x;
}

std::vector<std::vector<bool>> bombs;
std::vector<std::vector<int>> game_table;

Window::Window(int n, int m) {

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

    for (int i = 0; i > n; i++) {
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

    this->flags = Gtk::Label();
    flags.set_label("flags left: " + std::to_string(n_bombs));
    this->flags.show();
    this->all_box.add(this->flags);

    for (int i = 0; i < n; i++) {
        this->box = Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL);
        this->box.set_valign(Gtk::ALIGN_CENTER);

        for (int j = 0; j < m; j++) {
            if (bombs[i][j]) {
                this->bomb = Gtk::Button("b");
                bomb.set_size_request(40, 40);
                bomb.set_border_width(5);
                this->box.add(this->bomb);
                this->bomb.show();
                this->bomb.signal_clicked().connect(sigc::mem_fun(*this, &Window::click_bomb));
            } else {
                this->no_bomb = Gtk::Button("n");
                no_bomb.set_size_request(40, 40);
                no_bomb.set_border_width(5);
                this->box.add(this->no_bomb);
                this->no_bomb.show();
                this->no_bomb.signal_clicked().connect(sigc::mem_fun(*this, &Window::click_no_bomb));
            }
        }
        this->box.show();
        this->all_box.add(this->box);
    }

    this->add(this->all_box);
    this->all_box.show();
}

Window::~Window() = default;

void Window::click_no_bomb() {
    int x, y = 0;
    no_bomb.set_label(std::to_string(game_table[x][y]));
    std::cout << "click!\n";
}

void Window::click_bomb() {
    std::cout << "boom!\n";
}
