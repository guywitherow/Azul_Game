#include <iostream>
#include "Factory.h"


Factory::Factory() {
   //tile vector created, no inital values, depends on the size
}

Factory::~Factory() {
   tiles.clear();
}

void Factory::printFactory() {

   for (auto i = tiles.begin(); i != tiles.end(); i++) {
      std::cout << i->tileToChar();
   }
}
   
int Factory::removeTile(TileType type) {
   int removedTileCount = 0;
   int toDelete[5];
   int currentTile = 0;
   for (auto i = tiles.begin(); i != tiles.end(); i++) {
      if (i->getType() == type) {
         toDelete[removedTileCount] = currentTile;
         removedTileCount++;
         tileCount--;
      }
      currentTile++;
   }
   
   for (int i = 0; i < removedTileCount; i++) {
      int index = toDelete[i] - i;
      tiles.erase(tiles.begin() + index);
   }

   for (int i = 0; i < removedTileCount; i++) {
      tiles.push_back(Tile());
   }

   return removedTileCount;
}

void Factory::addTile(Tile tile) {
   tiles.push_back(tile);
   tileCount++;
}

void Factory::clearFactory() {
   //remove all from the vector
}

std::vector<Tile> Factory::getTiles() {
   return tiles;
}

int Factory::getTileCount() {
   return tileCount;
}