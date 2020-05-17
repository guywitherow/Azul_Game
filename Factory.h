#ifndef FACTORY_H
#define FACTORY_H


#include <vector>
#include "Tile.h"

class Factory {

   public:
   Factory();
   ~Factory();
   int removeTile(TileType type);
   void addTile(Tile tile);
   void clearFactory();
   void printFactory();
   int getTileCount();

   private:
   std::vector<Tile> tiles;
   int tileCount = 0;

};

#endif