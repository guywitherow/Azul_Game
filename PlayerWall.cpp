#include "PlayerWall.h"

//set up empty buffer and wall and floor
PlayerWall::PlayerWall() {
   //wall needs to have all tiles init, otherwise we will get a
   //nullptr 
   for (int i = 0; i < WALL_DIM; i++) {
      for (int j = 0; j < WALL_DIM; j++) {
         wall[i][j] = Tile();
      }
   }

   for (int i = 0; i < WALL_DIM; i++) {
      int size = i + 1;
      storage[i].resize(size, Tile());
   }

   //so we can check it's size against the expected
   //floor does need to be init
   for (int i = 0; i < FLOOR_DIM; i++) {
      floor[i] = Tile();
   }
}

PlayerWall::~PlayerWall() {

}

//get a line of the storage
std::vector<Tile> PlayerWall::getStorageLine(int line) {
   return storage[line];
}

//get a line of the wall by direction
Tile* PlayerWall::getWallLine(int line, Direction direction) {

   static Tile returnLine[WALL_DIM];

   if (direction == Direction::VERTICAL) {
      for (int i = 0; i < WALL_DIM; i++) {
         returnLine[i] = wall[i][line];
      }
   }
   else {
      for (int i = 0; i < WALL_DIM; i++) {
         returnLine[i] = wall[line][i];
      }
   }

   return returnLine;
}

//get the floor line, for scoring and for changing
Tile* PlayerWall::getFloorLine() {
   static Tile returnLine[FLOOR_DIM];
   for (int i = 0; i < FLOOR_DIM; i++) {
      returnLine[i] = floor[i];
   }

   return returnLine;
}

//return a string representation for printing of the buffer, wall and floor
//as shown in the documentation
/*
* This method retreives the wall as a string
*/
std::string PlayerWall::getPlayerWallString() {
   std::string returnString = "";
   for (int i = 0; i < WALL_DIM; i++) {
      int lineNumber = i + 1;
      returnString += std::to_string(lineNumber);
      returnString += ":";
      //get data
      std::vector<Tile> bufferLine = getStorageLine(i);
      Tile* wallLine = getWallLine(i, Direction::HORIZONTAL);

      //construct string
      for (int j = i; j < 5; j++) {
         returnString += " ";
      }

      for (std::size_t i = 0; i < bufferLine.size(); ++i) {
         returnString += bufferLine.at(i).tileToChar();
      }
      returnString += " || ";

      std::string wallLineString = "";
      for (int j = 0; j < WALL_DIM; j++) {
         returnString += wallLine[j].tileToChar();
      }

      returnString += wallLineString;
      returnString += '\n';
   }

   std::string floor = "";

   Tile* floorTiles = getFloorLine();

   returnString += "broken: ";
   for (int j = 0; j < 7; j++) {
      returnString += floorTiles[j].tileToChar();
   }
   returnString += '\n';
   return returnString;
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
