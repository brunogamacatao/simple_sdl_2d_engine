#include "tmxparser/Tmx.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

void load_map(std::string fileName) {
  Tmx::Map *map = new Tmx::Map();
  map->ParseFile(fileName);

  if (map->HasError()) {
    std::cout << "Erro: " << map->GetErrorCode() << std::endl;
  } else {
    printf("Version: %1.1f\n", map->GetVersion());
    printf("Orientation: %d\n", map->GetOrientation());

    if (!map->GetBackgroundColor().IsTransparent())
      printf("Background Color (hex): %s\n", map->GetBackgroundColor().ToString().c_str());

    printf("Render Order: %d\n", map->GetRenderOrder());

    if (map->GetStaggerAxis())
      printf("Stagger Axis: %d\n", map->GetStaggerAxis());

    if (map->GetStaggerIndex())
      printf("Stagger Index: %d\n", map->GetStaggerIndex());

    printf("Width: %d\n", map->GetWidth());
    printf("Height: %d\n", map->GetHeight());
    printf("Tile Width: %d\n", map->GetTileWidth());
    printf("Tile Height: %d\n", map->GetTileHeight());
  }
}
