#include "eight_directions.h"

EightDirections::EightDirections(string texture, double x, double y, double speed) : Sprite(texture, x, y) {
  _speed = speed;
}

void EightDirections::update() {
  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

  double delta = Clock::getInstance().deltaTime * _speed;

  if (currentKeyStates[SDL_SCANCODE_UP])    setY(getY() - delta);
  if (currentKeyStates[SDL_SCANCODE_DOWN])  setY(getY() + delta);
  if (currentKeyStates[SDL_SCANCODE_LEFT])  setX(getX() - delta);
  if (currentKeyStates[SDL_SCANCODE_RIGHT]) setX(getX() + delta);
}
