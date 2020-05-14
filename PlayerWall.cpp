#include "PlayerWall.h"

PlayerWall::PlayerWall() {

}

PlayerWall::~PlayerWall() {
   
}

//get a line of the storage
Tile* getStorageLine(int line) {

   return nullptr;
}

//get a line of the wall by direction
Tile* getWallLine(int line, Direction direction) {

   return nullptr;
}

//get the floor line, for scoring and for changing
Tile* getFloorLine() {
   return nullptr;
}

//add tiles to storage line, any excess go to the floor
void addToStorageLine(Tile* tiles, int line) {

}

//will be complex, follow steps on the flowchart for scoring
//vertical lines
//horizontal lines
//adjacent tiles
//if a complete horizontal line is reached, we need to flag game over
//(BASICLY A SCORE FUNCTION)
void moveStorageToWall() {

}


//clears storage
void clearStorage() {

}

//clears wall
void clearWall() {

}

//clears floor
void clearFloor() {

}
