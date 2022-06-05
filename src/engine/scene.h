#ifndef _SCENE_H
#define _SCENE_H

#include <list>
#include "types.h"

class Scene {
  private:
    std::list<Sprite *> _sprites;
  public:
    Scene() {}
    ~Scene();

    void addSprite(Sprite *sprite);
    void draw();
    void update();

    virtual void beforeUpdate();
    virtual void afterUpdate();
    virtual void beforeDraw();
    virtual void afterDraw();
};

#endif