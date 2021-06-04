#include "World.hpp"
#include <iostream>
#include <random>
#include <functional>

World::World(int width, int height): width_(width), height_(height) {
    elevation_ = new int[width*height];
    for (int x=0;x<width;x++) {
        for (int y=0;y<height;y++) {
            set_elevation(x,y,0);
        }
    }

    /* Load the animations */
    texture_.setSmooth();
    for (int anim = 0; anim<6;anim++)
        animation_[anim].addTileset(texture_, gf::vec(10, 6), gf::milliseconds(80), 10, 10*anim);

}
World::~World(){
    delete[] elevation_;
}

void World::update(gf::Time /*time*/) {
    tick_ ++;

}

Walker* World::makeWalker(float x, float y) {
    auto walker = new Walker(x, y);
    walker->setAnimation(animation_[0]);
    walkers_.push_back(walker);
    return walker;
}

const std::vector<Walker*>& World::getWalkers() const {
    return walkers_;
}