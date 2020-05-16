#include "PlayerWall.h"


//set up empty buffer and wall and floor
PlayerWall::PlayerWall() {

}

PlayerWall::~PlayerWall() {
   
}

//get a line of the storage
std::vector<Tile*> PlayerWall::getStorageLine(int line) {
   return storage[line];
}

//get a line of the wall by direction
Tile* PlayerWall::getWallLine(int line, Direction direction) {

   Tile* returnLine = nullptr;

   if (direction == VERTICAL) {
      for (int i = 0; i < WALL_DIM; i++) {
         returnLine[i] = *wall[i][line];
      }
   }
   else {
      returnLine = *wall[line];
   }

   return returnLine;
}

//get the floor line, for scoring and for changing
Tile* PlayerWall::getFloorLine() {
   return *floor;
}

std::string PlayerWall::getPlayerWall() {
   return "";
}

//add tiles to storage line, any excess go to the floor
void PlayerWall::addToStorageLine(Tile* tiles, int line) {

}

//will be complex, follow steps on the flowchart for scoring
//vertical lines
//horizontal lines
//adjacent tiles
//if a complete horizontal line is reached, we need to flag game over
//(BASICLY A SCORE FUNCTION)
void PlayerWall::moveStorageToWall() {

}


//clears storage
void PlayerWall::clearStorage() {

}

//clears wall
void PlayerWall::clearWall() {

}

//clears floor
void PlayerWall::clearFloor() {

}
