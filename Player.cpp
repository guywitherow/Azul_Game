#include "Player.h"
#include <string>


Player::Player(std::string name) {
   this->playerName = name;
   this->wall = new PlayerWall();
}

Player::~Player()
{
 delete this->wall;
}

void Player::load(std::string data, int dataID) {

   if (dataID == 0) {
      setName(data);
   }
   else if (dataID >= 1 && dataID <= 5) {
      std::vector<Tile> tilesToAdd;
      for (unsigned i = 0; i < dataID; ++i)
      {
         tilesToAdd.push_back(Tile::charToTile(data.at(i)));
      }

      getWall()->setBufferLine(tilesToAdd, dataID - 1);
   }
   else if (dataID >= 6 && dataID <= 10) {
      std::vector<Tile> tilesToAdd;
      for (unsigned i = 0; i < data.length(); ++i)
      {
         tilesToAdd.push_back(Tile::charToTile(data.at(i)));
      }

      getWall()->setWallLine(tilesToAdd, dataID - 6);
   }
   else if (dataID == 11) {
      std::vector<Tile> tilesToAdd;
      for (int i = 0; i < data.length(); i++) {
         TileType current = Tile::charToTile(data.at(i));
         if (current == TileType::NO_TILE) {
            i = FLOOR_DIM;
         }
         else {
            getWall()->addToFloorLine(current, 1);
         }
      }
      
   }
   else if (dataID == 12) {
      try {
         score = std::stoi(data);
      }
      catch (...) {
         score = 0;
      }
   }

}


std::string Player::getName() {
   return playerName;
}

void Player::setName(std::string name) {
   playerName = name;
}

PlayerWall* Player::getWall() {
   return wall;
}

int Player::getScore() {
   return this->score;
}

void Player::setScore(int score) {
   this->score = score;
}

void Player::setWall(PlayerWall* wall) {
   delete this->wall;
   this->wall = wall;
}
