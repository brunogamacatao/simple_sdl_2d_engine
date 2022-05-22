#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <map>
#include <fmt/core.h>
#include "scene.h"
#include "game.h"

using namespace std;

Game::Game(string title, int width, int height) {
  _title  = title;

  GameEnvironment::getInstance().width = width;
  GameEnvironment::getInstance().height = height;
  GameEnvironment::getInstance().game = this;

  init();
}

Game::~Game() {
  _scenes.clear();
  SDL_DestroyWindow(GameEnvironment::getInstance().window);
  SDL_Quit();
}

void Game::init() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw fmt::format("SDL could not initialize! SDL_Error: {}", SDL_GetError());
  }

  // Create window
  GameEnvironment::getInstance().window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GameEnvironment::getInstance().width, GameEnvironment::getInstance().height, SDL_WINDOW_SHOWN);
  if (!GameEnvironment::getInstance().window) {
    throw fmt::format("Window could not be created! SDL_Error: {}", SDL_GetError());
  }

  // Get window surface
  GameEnvironment::getInstance().screenSurface = SDL_GetWindowSurface(GameEnvironment::getInstance().window);
}

void Game::loop() {
  bool quit = false;
  SDL_Event e;

  while(!quit) {
    while(SDL_PollEvent(&e) != 0) {
      if(e.type == SDL_QUIT) {
        quit = true;
      }
    }

    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_ESCAPE]) quit = true;


    clearScreen(0x00, 0x00, 0x00);

    if (_currentScene) {
      _currentScene->update();
      _currentScene->draw();
    }

    SDL_UpdateWindowSurface(GameEnvironment::getInstance().window);
    Clock::getInstance().tick();
  }
}

void Game::clearScreen(Uint8 r, Uint8 g, Uint8 b) {
  SDL_FillRect(GameEnvironment::getInstance().screenSurface, NULL, SDL_MapRGB(GameEnvironment::getInstance().screenSurface->format, r, g, b));
}

void Game::addScene(string sceneName, Scene *scene) {
  _scenes[sceneName] = scene;
}

void Game::goToScene(string sceneName) {
  _currentScene = _scenes[sceneName];
}
