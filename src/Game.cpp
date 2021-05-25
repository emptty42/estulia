#include "Game.hpp"
#include "World.hpp"
#include "View.hpp"
#include <gf/Event.h>
#include <iostream>

static const int width = 800;
static const int heigth = 600;

Game::Game()  {
}

int Game::run() {

    auto world = std::make_shared<World>(width, heigth);
    View view(world, &window_);

  gf::Clock clock;

  while (window_.isOpen()) {
    gf::Event event;

    while (window_.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window_.close();
          break;

        case gf::EventType::KeyPressed:
          if (event.key.scancode == gf::Scancode::Escape) {
            window_.close();
          }
          break;

        default:
          break;
      }
    }

    gf::Time time = clock.restart();
    world->update(time);
    view.display(time);
  }
    return EXIT_SUCCESS;
}

int main(int, char const**) {
    return Game().run();
}
