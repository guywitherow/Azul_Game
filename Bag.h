#ifndef BAG_H
#define BAG_H

#include "Tile.h"
#include "LinkedList.h"
#include <random>

class Bag
{
public:
   Bag(int seed);
   ~Bag();

   void clear();

   int size();
   void fill();
   void shuffle();
   Tile getTopTile();
   LinkedList getAllTiles();

   private:

      // This Generates a temporary linkedlist that contains all the tiles in order 
      LinkedList* tempLinkedList;

      // Randomizes the Tiles in the temporary linkedlist and stores them in this linkedlist.
      // This linkedlist will be the main linkedlist where players take tiles from.
      LinkedList* bagLinkedList;
};
#endif