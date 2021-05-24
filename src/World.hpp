#ifndef INCLUDE_WORLD_HPP
#define INCLUDE_WORLD_HPP

#include <gf/Time.h>

class View;

class World {
    friend View;

    bool running_ = true;
    unsigned long tick_ = 0;
    int width_;
    int height_;
    int *elevation_;
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
};

#endif
