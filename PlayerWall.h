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

   std::vector<Tile> getStorageLine(int line);
   Tile* getWallLine(int line, Direction direction);
   Tile* getFloorLine();

   std::string getPlayerWallString();
   void addToStorageLine(TileType type, int count, int line);
   void addToFloorLine(TileType type, int count);

   void moveStorageToWall();

   void clearStorage();
   void clearWall();
   void clearFloor();

private:
   std::vector<Tile> storage[5];
   Tile wall[WALL_DIM][WALL_DIM];
   Tile floor[FLOOR_DIM];
   int tilesOnFloor = 0;

};

#endif