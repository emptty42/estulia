#ifndef ESTULIA_GAME_HPP
#define ESTULIA_GAME_HPP

#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <memory>

class Game {
    gf::Window window_ = gf::Window("Estulia", { 640, 480 }, ~gf::WindowHints::Resizable);

public:
    Game();
    int run();
    void quit();
};

#endif
