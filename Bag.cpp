#include "Bag.h"
#include "LinkedList.h"

Bag::Bag(int seed) {
   tempLinkedList = new LinkedList();
   bagLinkedList = new LinkedList();

   for (int i = 0; i < 100; i++) {
      TileType tileData;
      if (i < 20) {
         tileData = TileType::RED;
      }
      else if (i < 40) {
         tileData = TileType::DARK_BLUE;
      }
      else if (i < 60) {
         tileData = TileType::LIGHT_BLUE;
      }
      else if (i < 80) {
         tileData = TileType::BLACK;
      }
      else {
         tileData = TileType::YELLOW;
      }
      tempLinkedList->addBack(tileData);
   }
}


Bag::~Bag() {
   clear();
}

void Bag::clear() {
   delete tempLinkedList;
   delete bagLinkedList;
}

//how many tiles left?
int Bag::size() {
   return bagLinkedList->getSize();
}



//merhawi's shuffle function
void Bag::shuffle() {
   int min = 0;
   int max = tempLinkedList->getSize();
   int index = -1;
   std::random_device engine;

   for (int i = 0; i < max; ++i) {
      int size = tempLinkedList->getSize() - 1;
      std::uniform_int_distribution<int> uniform_dist(min, size);
      index = uniform_dist(engine);
      tempLinkedList->transferTo(index, bagLinkedList);
   }
}

void Bag::fill() {
   for (int i = 0; i < 100; i++) {
      TileType tileData = TileType::NO_TILE;
      if (i < 20) {
         tileData = TileType::RED;
      }
      else if (i < 40) {
         tileData = TileType::DARK_BLUE;
      }
      else if (i < 60) {
         tileData = TileType::LIGHT_BLUE;
      }
      else if (i < 80) {
         tileData = TileType::BLACK;
      }
      else {
         tileData = TileType::YELLOW;
      }
      tempLinkedList->addBack(tileData);
   }
}

//get the backmost tile, or the front
Tile Bag::getTopTile() {
   Tile returnTile = Tile(bagLinkedList->transferBack());
   return returnTile;
}
