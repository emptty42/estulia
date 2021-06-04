#include "View.hpp"
#include <gf/RenderWindow.h>
#include <iostream>

View::View(std::shared_ptr<World> world, gf::Window* window): world_(world), 
    renderer_(std::make_shared<gf::RenderWindow>(*window)) {


    renderer_->clear(gf::Color::White);
}

void View::display(gf::Time time) {
    renderer_->clear();
    for(auto &sprite : world_->getWalkers()) {
        sprite->update(time);
        renderer_->draw(*sprite);
    }
    renderer_->display();

}

