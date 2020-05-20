#include "Bag.h"
#include "LinkedList.h"

Bag::Bag(int seed) {
   tempLinkedList = new LinkedList();
   bagLinkedList = new LinkedList();
}


Bag::~Bag() {
   tiles.clear();
}

//how many tiles left?
int Bag::size() {
   return tiles.getSize();
}

//merhawi's shuffle function
void Bag::shuffle() {
   int min = 0;
   int max = tempLinkedList->getSize();
   int index = -1;
   std::random_device engine;

   for(int i = 0; i < max; ++i) {
      int size = tempLinkedList->getSize() - 1;
      std::uniform_int_distribution<int> uniform_dist(min, size);
      index = uniform_dist(engine);
      tempLinkedList->transferTo(index,bagLinkedList);
   }

}

void Bag::fill() {
   for (int i = 0; i < 100; i++) {
      Tile* tileData;
      if (i < 20) {
         tileData = new Tile(TileType::RED);
      }
      else if (i < 40) {
         tileData = new Tile(TileType::DARK_BLUE);
      }
      else if (i < 60) {
         tileData = new Tile(TileType::LIGHT_BLUE);
      }
      else if (i < 80) {
         tileData = new Tile(TileType::BLACK);
      }
      else {
         tileData = new Tile(TileType::YELLOW);
      }
      tiles.addBack(tileData);
   }
}

//get the backmost tile, or the front
Tile Bag::getTopTile() {
   Tile returnTile = *tiles.getTile(0);
   tiles.deleteBack();
   return returnTile;
}
