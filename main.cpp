// Using SDL and standard IO
#include <iostream>
#include <string>
#include "engine/types.h"
#include "engine/game.h"
#include "engine/scene.h"
#include "engine/sprite.h"
#include "behaviors/eight_directions.h"

using namespace std;

class Scene01 : public Scene {
  public:
    Scene01() : Scene() {
      addSprite(new Sprite("images/background.png", 0, 0));
      addSprite(new EightDirections("images/sonic.png", 10, 10, 0.2));
    }

    void afterUpdate() {
      const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
      if (currentKeyStates[SDL_SCANCODE_RETURN]) {
        GameEnvironment::getInstance().game->goToScene("scene02");
      }
    }
};

class Scene02 : public Scene {
  public:
    Scene02() : Scene() {
      addSprite(new EightDirections("images/mario.png", 10, 10, 1.0));
    }

    void afterUpdate() {
      const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
      if (currentKeyStates[SDL_SCANCODE_SPACE]) {
        GameEnvironment::getInstance().game->goToScene("scene01");
      }
    }
};

int main() {  
  // Inicializa game engine
  Game game = Game("Minha Engine", 640, 480);

  // Adiciona as cenas no jogo
  game.addScene("scene01", new Scene01());
  game.addScene("scene02", new Scene02());

  // Definindo a cena inicial
  game.goToScene("scene01");

  // Game loop
  game.loop();

  return 0;
}