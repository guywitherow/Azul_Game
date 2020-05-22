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

   tilesOnFloor = 0;
}

PlayerWall::~PlayerWall() {

}

//get a line of the storage
std::vector<Tile> PlayerWall::getStorageLine(int line) {
   return storage[line];
}

void PlayerWall::setBufferLine(std::vector<Tile> added, int line) {
   for (int i = 0; i < line + 1; i++) {
      storage[line][i] = added.at(i);
   }
}

void PlayerWall::setWallLine(std::vector<Tile> added, int line) {
   for (int i = 0; i < WALL_DIM; i++) {
      wall[line][i] = added.at(i);
   }
}

bool PlayerWall::checkWallLineForType(int line, TileType type) {
   bool found = false;
   for (int i = 0; i < WALL_DIM; i++) {
      if (wall[line][i].getType() == type){
         found = true;
      }
   }
   return found;
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
void PlayerWall::addToStorageLine(TileType type, int count, int line) {
   int currentTilesOnBuffer = 0;
   TileType typeOnLine = TileType::NO_TILE;
   for (int j = 0; j < line + 1; j++) {
      if (storage[line].at(j).getType() != TileType::NO_TILE) {
         currentTilesOnBuffer++;
         typeOnLine = storage[line].at(j).getType();
      }
   }
   if (type == typeOnLine || typeOnLine == TileType::NO_TILE) {
      for (int i = 0; i < count; i++) {
         if (currentTilesOnBuffer > line) {
            addToFloorLine(type, 1);
         }
         else {
            storage[line][currentTilesOnBuffer++] = Tile(type);
         }
      }
   }
   else {
      for (int i = 0; i < count; i++) {
         addToFloorLine(type, 1);
      }
   }

   
}

void PlayerWall::addToFloorLine(TileType type, int count) {
   for (int i = 0; i < count; i++) {
      if (tilesOnFloor < 7) {
         floor[tilesOnFloor++] = Tile(type);
      }
      if (type == TileType::NO_TILE) {
         tilesOnFloor--;
      }
      //if there are 7, discard
   }
}


//will be complex, follow steps on the flowchart for scoring
//vertical lines
//horizontal lines
//adjacent tiles
//if a complete horizontal line is reached, we need to flag game over
//(BASICLY A SCORE FUNCTION)
int PlayerWall::moveStorageToWall() {
   int score = 0;

   for (int i = 0; i < WALL_DIM; i++) {
      std::vector<Tile> currentBuffer = storage[i];
      int tilesInBuffer = 0;
      for (int j = 0; j < i + 1; j++) {
         if (currentBuffer.at(j).getType() != TileType::NO_TILE) {
            tilesInBuffer++;
         }
      }

      //full line in buffer?
      //move them
      if (tilesInBuffer > i) {
         int scoreToAdd = 0;
         TileType addToWall = currentBuffer.at(0).getType();
         char tiles[WALL_DIM] = { 'B', 'Y', 'R', 'U', 'L' };

         for (int j = 0; j < WALL_DIM; j++) {
            int tileNumber = (j + i) % 5;
            if (addToWall == Tile::charToTile(tiles[j])) {
               wall[i][j] = Tile(addToWall);

               scoreToAdd = checkScore(i, j);

            }
         }
         std::cout << std::endl;
         score += scoreToAdd;

         storage[i].clear();
         resetStorageLine(i);
      }
   }

   return score;
}

void PlayerWall::resetStorageLine(int line) {

   storage[line].resize(line + 1, Tile());

}

int PlayerWall::checkScore(int y, int x) {
   std::vector<Tile> tileLine;
   int loopNum = 0;
   int score = 1;

   while (loopNum < 2) {
      if (loopNum == 0) {
         for (int i = 0; i < WALL_DIM; i++) {
            tileLine.push_back(wall[y][i]);
         }
      }
      else {
         for (int i = 0; i < WALL_DIM; i++) {
            tileLine.push_back(wall[i][x]);
         }
      }

      int streak = 0;
      bool seenTarget = false;
      for (int i = 0; i < WALL_DIM; i++) {
         if (tileLine.at(i).getType() != TileType::NO_TILE) {
            streak++;
            if (tileLine.at(i).getType() == wall[y][x].getType()) {
               seenTarget = true;
            }
         }
         else {
            if (seenTarget) {
               i = WALL_DIM;
            }
            else {
               streak = 0;
            }
         }
      }
      score += streak;
      loopNum++;
   }
   
   return score;
}