#ifndef _SPRITE_H
#define _SPRITE_H
#include <string>
#include <list>
#include <SDL2/SDL.h>
#include "types.h"

class Sprite {
  private:
    std::string _path;
    double _x;
    double _y;
    double _width;
    double _height;
    bool _scaled;
    SDL_Surface *_texture;
  
    SDL_Surface *loadSurface(std::string path);
  public:
    bool _loaded = false;
    
    Sprite(std::string path, double x, double y);
    Sprite(std::string path, double x, double y, double width, double height);
    ~Sprite();

    void load();
    void draw();

    double getX();
    double getY();

    void setX(double x);
    void setY(double y);

    virtual void update();
};
#endif