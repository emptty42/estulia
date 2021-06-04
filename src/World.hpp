#ifndef ESTULIA_WORLD_HPP
#define ESTULIA_WORLD_HPP

#include <Walker.hpp>

#include <gf/Animation.h>
#include <gf/Texture.h>
#include <gf/Time.h>

class View;

class World {
    friend View;

    bool running_ = true;
    unsigned long tick_ = 0;
    int width_;
    int height_;
    int *elevation_;
    std::vector<Walker*> walkers_;

    /* Hold the memory for all graphical resources */
    gf::Animation animation_[6];
    gf::Texture texture_{"data/carrier_walk.png"};

public:
    World(int width, int height);
    ~World();
    int getWidth() { return width_;}
    int getHeight() { return height_;}
    unsigned long getTick() {return tick_;}

    void set_elevation(int x, int y, int elevation){
        elevation_[x*height_+y] = elevation;
    }
    int get_elevation(int x, int y){
        return elevation_[x*height_+y];
    }

    void update(gf::Time time);
    bool running() { return running_;}
    void stop() {running_ = false;}

    Walker* makeWalker(float x, float y);
    const std::vector<Walker*>& getWalkers() const;
};

#endif
