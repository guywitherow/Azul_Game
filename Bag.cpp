#include "Bag.h"
#include "LinkedList.h"

Bag::Bag(int seed) {
    tempLinkedList = new LinkedList();
    bagLinkedList = new LinkedList();

   for (int i = 0; i < 100; i++) {

      Tile* tileData;
      if (i < 20) {
         tileData = new Tile(RED);
      }
      else if (i < 40) {
         tileData = new Tile(DARK_BLUE);
      }
      else if (i < 60) {
         tileData = new Tile(LIGHT_BLUE);
      }
      else if (i < 80) {
         tileData = new Tile(BLACK);
      }
      else {
         tileData = new Tile(YELLOW);
      }

      tiles.addBack(tileData);
   }

   //shuffle bag

}


Bag::~Bag() {

//delete all tiles in bag using linkedlist deconstructor

}

//how many tiles left?
int size() {
   return 0;
}

//merhawi's shuffle function
void shuffle() {
   int min = 0;
    int max = tempLinkedList->getSize();
    int index = -1;
    std::random_device engine;

    for(int i = 0; i < max; ++i) {
        int size = tempLinkedList->getSize() - 1;
        std::uniform_int_distribution<int> uniform_dist(min, size);
        index = uniform_dist(engine);
        tempLinkedList->transferAt(index,bagLinkedList);
    }

}

//get the backmost tile, or the front
Tile getTopTile() {
   Tile tile(RED);
   return tile;
}

