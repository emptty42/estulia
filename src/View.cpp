#include "View.hpp"
#include <gf/RenderWindow.h>
#include <iostream>

void View::initAssets() {
    if (not View::walkers_.empty()) // Don't call this function twice
        return;

}

View::View(std::shared_ptr<World> world, gf::Window* window): world_(world), window_(window),
    renderer_(std::make_shared<gf::RenderWindow>(*window_)) {
    initAssets();

    renderer_->clear(gf::Color::White);
}

void View::display() {
    renderer_->clear();
//    renderer_->draw(animatedSprite);
    renderer_->display();

}

