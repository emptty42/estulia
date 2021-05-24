#ifndef INCLUDE_VIEW_HPP
#define INCLUDE_VIEW_HPP

#include "World.hpp"
#include <gf/AnimatedSprite.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <memory>
#include <unordered_map>

class View {
    std::shared_ptr<World> world_;

    gf::Window* window_;
    std::shared_ptr<gf::RenderWindow> renderer_;

    void initAssets();

    std::vector<gf::AnimatedSprite*> walkers_;

public:
    View(std::shared_ptr<World> world, gf::Window* window);
    void display();
    void update(gf::Time time);
};
#endif
