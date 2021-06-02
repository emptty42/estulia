#include "View.hpp"
#include <gf/RenderWindow.h>
#include <iostream>

View::View(std::shared_ptr<World> world, gf::Window* window): world_(world), 
    renderer_(std::make_shared<gf::RenderWindow>(*window)) {

    /* Load the animations */
    texture_.setSmooth();
    for (int anim = 0; anim<6;anim++)
        animation_[anim].addTileset(texture_, gf::vec(10, 6), gf::milliseconds(80), 10, 10*anim);

    renderer_->clear(gf::Color::White);

    /* Create a walker */
    gf::AnimatedSprite animatedSprite;
    animatedSprite.setAnimation(animation_[0]);
    animatedSprite.setPosition({ 320, 240 }); 
    animatedSprite.setOrigin({ 224 / 2.0f, 364 / 2.0f });

    walkers_.push_back(animatedSprite);
}

void View::display(gf::Time time) {
    renderer_->clear();
    for(auto &sprite : walkers_) {
        sprite.update(time);
        renderer_->draw(sprite);
    }
    renderer_->display();

}

