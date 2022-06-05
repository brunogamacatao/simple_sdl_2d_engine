#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <fmt/core.h>
#include "sprite.h"

using namespace std;

Sprite::Sprite(string path, double x, double y) {
  _path   = path;
  _x      = x;
  _y      = y;
  _scaled = false;
}

Sprite::Sprite(std::string path, double x, double y, double width, double height) {
  _path   = path;
  _x      = x;
  _y      = y;
  _width  = width;
  _height = height;
  _scaled = true;
}

Sprite::~Sprite() {
  SDL_FreeSurface(_texture);
}

void Sprite::load() {
  _texture = loadSurface(_path);
  _loaded = true;

  if (!_scaled) {
    _width  = _texture->clip_rect.w;
    _height = _texture->clip_rect.h;
  }
}

void Sprite::draw() {
  if (!_loaded) {
    load();
  }

  SDL_Rect dest;

  dest.x = (int)_x;
  dest.y = (int)_y;
  dest.w = (int)_width;
  dest.h = (int)_height;

  if (_scaled) {
    SDL_BlitScaled(_texture, NULL, GameEnvironment::getInstance().screenSurface, &dest);
  } else {
    SDL_BlitSurface(_texture, NULL, GameEnvironment::getInstance().screenSurface, &dest);
  }
}

double Sprite::getX() {
  return _x;
}

double Sprite::getY() {
  return _y;
}

void Sprite::setX(double x) {
  _x = x;
}

void Sprite::setY(double y) {
  _y = y;
}

SDL_Surface *Sprite::loadSurface(string path) {
  SDL_Surface *loadedSurface = IMG_Load(path.c_str());

  if (loadedSurface == NULL) {
    throw fmt::format("Unable to load image {}! SDL_image Error: {}", path.c_str(), IMG_GetError());
  }

  if (_scaled) {
    SDL_Surface *optimizedSurface = SDL_ConvertSurface(loadedSurface, GameEnvironment::getInstance().screenSurface->format, 0);
    SDL_FreeSurface(loadedSurface);
    return optimizedSurface;
  }

  return loadedSurface;
}

void Sprite::update() {}