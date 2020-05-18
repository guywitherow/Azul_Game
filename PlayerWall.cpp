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

//return a string representation for printing of the buffer, wall and floor
//as shown in the documentation
/*
      Mosaic for <player-name>:
      *** this bit
      1:         . || . . R . .
      2:       Y Y || . . . R .
      3:     B B B || . . . . .
      4:   . . . . || . . L . .
      5: . . U U U || . . . . .
      broken: F Y
      ***
*/
std::string PlayerWall::getPlayerWall() {
   std::string returnString = "";
   for (int i = 0; i < WALL_DIM; i++) {
      //get data
      std::vector<Tile*> bufferLine = getStorageLine(i);
      Tile* wallLine = getWallLine(i, HORIZONTAL);

      //construct strings

      std::string bufferLineString = "";
      for (int j = i; j < 5; j++) {
         bufferLineString =+ " ";
      }
      for (int j = 0; j < bufferLine.size(); j++) {
         bufferLineString =+ bufferLine.at(j)->tileToChar();
      }
      

      std::string wallLineString = "";
      for (int j = 0; j < WALL_DIM; j++) {

      }


      //add to super return string



      returnString += i+1 + ":";
      returnString += bufferLineString;
      returnString += " || ";
      returnString += wallLineString;
      returnString += '\n';
   }

   std::string floor = "";

   Tile* floorTiles = getFloorLine();

   

   returnString += "broken: ";
   

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
