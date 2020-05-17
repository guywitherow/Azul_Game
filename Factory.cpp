#include <iostream>
#include "Factory.h"


Factory::Factory() {
   //tile vector created, no inital values, depends on the size
}

Factory::~Factory() {
   tiles.clear();
}

void Factory::printFactory() {
   if (tileCount > 0) {
      for (auto i = tiles.begin(); i != tiles.end(); i++) {
         std::cout << i->tileToChar() << " ";
      }
   }
}
   
int Factory::removeTile(TileType type) {
   int tileCount = 0;
   for (auto i = tiles.begin(); i != tiles.end(); i++) {
      if (i->getType() == type) {
         tileCount++;
         tiles.erase(i);
      }
   }
   tileCount--;
   return tileCount;
}

void Factory::addTile(Tile tile) {
   tiles.push_back(tile);
   tileCount++;
}

void Factory::clearFactory() {
   //remove all from the vector
}

int Factory::getTileCount() {
   return tileCount;
}