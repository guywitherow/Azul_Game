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
      std::cout << i->getType();
   }
}
   
int Factory::removeTile(TileType type) {
   for (auto i = tiles.begin(); i != tiles.end(); i++) {
      if (i->getType() == type) {
         //add 1, remove this tile or (change it to a no-tile?)
      }
   }
}

void Factory::addTile(Tile tile) {
   //add a tile
}

void Factory::clearFactory() {
   //remove all from the vector
}