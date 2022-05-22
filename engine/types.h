#ifndef _TYPES_H
#define _TYPES_H

#include <SDL2/SDL.h>

// Incomplete types
class Game;
class Scene;
class Sprite;

// Singleton type to store global game environment variables
class GameEnvironment {
  private:
    GameEnvironment() {}
  public:
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    int width;
    int height;

    Game *game;

    static GameEnvironment& getInstance() {
      static GameEnvironment instance;
      return instance;
    }

    GameEnvironment(GameEnvironment const&) = delete;
    void operator=(GameEnvironment const&)  = delete;
};

class Clock {
  private:
    Uint64 now = 0;
    Uint64 last = 0;

    Clock() {
      now = SDL_GetPerformanceCounter();
    }

  public:
    double deltaTime = 0.0;

    static Clock& getInstance() {
      static Clock instance;
      return instance;
    }

    Clock(Clock const&)           = delete;
    void operator=(Clock const&)  = delete;

    void tick() {
      last = now;
      now = SDL_GetPerformanceCounter();

      deltaTime = ((now - last) * 1000 / (double)SDL_GetPerformanceFrequency());
    }
};

#endif