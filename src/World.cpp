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
}
World::~World(){
    delete elevation_;
}

void World::update(gf::Time /*time*/) {
    tick_ ++;

}
