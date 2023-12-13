#include <bits/stdc++.h>
#include "gtkmm.h"
#include "Window.h"


int main(int argc, char *argv[]) {
    int n, m;
    std::cout << "Enter the size of the field:";
    std::cin >> n >> m;

    auto app = Gtk::Application::create(argc, argv);

    Window window(n, m);

    return app->run(window);
}