#include "Bag.h"
#include "LinkedList.h"

Bag::Bag(int seed) {

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

}

void Bag::fill() {
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
}

//get the backmost tile, or the front
Tile Bag::getTopTile() {
   Tile returnTile = *tiles.getTile(0);
   tiles.deleteBack();
   return returnTile;
}

