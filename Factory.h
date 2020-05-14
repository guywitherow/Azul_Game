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

   private:
   std::vector<Tile> tiles;

};

#endif