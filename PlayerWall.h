#ifndef PLAYERWALL_H
#define PLAYERWALL_H

#include <string>
#include <vector>
#include "Types.h"
#include "Tile.h"

class PlayerWall {

  public:
   PlayerWall();
   ~PlayerWall();

   Tile* getStorageLine(int line);
   Tile* getWallLine(int line, Direction direction);
   Tile* getFloorLine();

   void addToStorageLine(Tile* tiles, int line);

   void moveStorageToWall();

   void clearStorage();
   void clearWall();
   void clearFloor();

  private:
   std::vector<Tile>** storage;
   Tile** wall[WALL_DIM][WALL_DIM];
   Tile* floor[FLOOR_DIM];

};

#endif