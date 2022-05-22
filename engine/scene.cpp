#include "types.h"
#include "scene.h"
#include "sprite.h"

#include <list>
#include <iterator>

using namespace std;

Scene::~Scene() {
  list<Sprite *>::iterator it;
  for (it = _sprites.begin(); it != _sprites.end(); ++it) {
    delete(*it);
  }
  _sprites.clear();
}

void Scene::addSprite(Sprite *sprite) {
  _sprites.push_back(sprite);
}

void Scene::draw() {
  beforeDraw();
  list<Sprite *>::iterator it;
  for (it = _sprites.begin(); it != _sprites.end(); ++it) {
    Sprite *sprite = *it;
    sprite->draw();
  }
  afterDraw();
}

void Scene::update() {
  beforeUpdate();
  list<Sprite *>::iterator it;
  for (it = _sprites.begin(); it != _sprites.end(); ++it) {
    Sprite *sprite = *it;
    sprite->update();
  }
  afterUpdate();
}

void Scene::beforeUpdate() {}
void Scene::afterUpdate() {}
void Scene::beforeDraw() {}
void Scene::afterDraw() {}