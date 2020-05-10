
#include <vector>
#include "Tile.h"
#include "LinkedList.h"

class Bag {
   public:
   Bag(int seed);
   ~Bag();

   int size();

   void shuffle();

   Tile getTopTile();

   private:

   LinkedList tiles;
};