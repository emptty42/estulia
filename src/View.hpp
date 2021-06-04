#ifndef ESTULIA_VIEW_HPP
#define ESTULIA_VIEW_HPP

#include "World.hpp"
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <memory>
#include <unordered_map>

class View {
    std::shared_ptr<World> world_;
    std::shared_ptr<gf::RenderWindow> renderer_;


public:
    View(std::shared_ptr<World> world, gf::Window* window);
    void display(gf::Time time);
};
#endif
