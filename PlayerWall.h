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

   int checkScore(int i, int j);

   void resetStorageLine(int line);

   bool checkWallLineForType(int line, TileType type);

   std::string getPlayerWallString();
   void addToStorageLine(TileType type, int count, int line);
   void addToFloorLine(TileType type, int count);

   void setBufferLine(std::vector<Tile>, int line);
   void setWallLine(std::vector<Tile>, int line);

   int moveStorageToWall();

private:
   std::vector<Tile> storage[5];
   Tile wall[WALL_DIM][WALL_DIM];
   Tile floor[FLOOR_DIM];
   int tilesOnFloor = 0;

};

#endif