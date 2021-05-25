#include "View.hpp"
#include <gf/RenderWindow.h>
#include <iostream>

View::View(std::shared_ptr<World> world, gf::Window* window): world_(world), 
    renderer_(std::make_shared<gf::RenderWindow>(*window)) {

    /* Load the animations */
    gf::Texture texture("data/carrier_walk.png");
    texture.setSmooth();
    for (int anim = 0; anim<6;anim++)
        for (unsigned frame = 0; frame < 10; ++frame)
            animation_[anim].addFrame(texture, gf::RectF::fromPositionSize({ 0.1f * frame, 1.f / 6.f * anim }, { 0.25f, 0.5f }), gf::milliseconds(100));

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

