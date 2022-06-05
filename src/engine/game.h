#ifndef _GAME_H
#define _GAME_H
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "types.h"

using namespace std;

class Game {
  private:
    string _title;
    map<string, Scene *> _scenes;
    Scene* _currentScene = NULL;

    void clearScreen(Uint8 r, Uint8 g, Uint8 b);
    void drawImage(SDL_Surface *image);
  public:
    Game(string title, int width, int height);
    ~Game();

    void init();
    void loop();

    void addScene(string sceneName, Scene *scene);
    void goToScene(string sceneName);
};
#endif