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
  _path = path;
  _x = x;
  _y = y;
}

Sprite::~Sprite() {
  SDL_FreeSurface(_texture);
}

void Sprite::load() {
  _texture = loadSurface(_path);
  _loaded = true;
}

void Sprite::draw() {
  if (!_loaded) {
    load();
  }

  SDL_Rect *dest = new SDL_Rect();
  dest->x = (int)_x;
  dest->y = (int)_y;
  dest->w = _texture->clip_rect.w;
  dest->h = _texture->clip_rect.h;
  SDL_BlitSurface(_texture, NULL, GameEnvironment::getInstance().screenSurface, dest);
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
  // The final optimized image
  SDL_Surface *optimizedSurface = NULL;

  // Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(path.c_str());
  if (loadedSurface == NULL) {
    throw fmt::format("Unable to load image {}! SDL_image Error: {}", path.c_str(), IMG_GetError());
  } else {
    // TODO - pensar em como usar o SDL_ConvertSurface com transparência do PNG
    optimizedSurface = loadedSurface;
    
    // Convert surface to screen format
    //optimizedSurface = SDL_ConvertSurface(loadedSurface, GameEnvironment::getInstance().screenSurface->format, 0);
    //if (optimizedSurface == NULL) {
    //  throw fmt::format("Unable to optimize image {}! SDL Error: {}", path.c_str(), SDL_GetError());
    //}
    //
    //// Get rid of old loaded surface
    //SDL_FreeSurface(loadedSurface);
  }

  return optimizedSurface;
}

void Sprite::update() {}