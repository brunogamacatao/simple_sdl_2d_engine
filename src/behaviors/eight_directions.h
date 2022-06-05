#ifndef EIGHT_DIRECTIONS_H
#define EIGHT_DIRECTIONS_H

#include <string>
#include "../engine/types.h"
#include "../engine/sprite.h"

using namespace std;

class EightDirections : public Sprite {
  private:
    double _speed;
  public:
    EightDirections(string texture, double x, double y, double speed);
    virtual void update();
};

#endif