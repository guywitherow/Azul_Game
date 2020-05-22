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

   //Player player = getPlayer(playerID);
   //data loaded in order
   //name
   //id?????
   //buffer 1
   //buffer 2
   //buffer ...
   //wall 1
   //wall 2
   //wall ...
   //floor
   //score

   if (dataID == 0) {
      setName(data);
   }
   else if (dataID >= 2 && dataID <= 6) {
      std::vector<Tile> tilesToAdd;
      for (unsigned i = 0; i < data.length(); ++i)
      {
         tilesToAdd.push_back(Tile::charToTile(data.at(i)));
      }


      getWall()->setBufferLine(tilesToAdd, dataID -3);
   }
   else if (dataID >= 7 && dataID <= 11) {
      //player.setWallLine(line,dataLine-8);
   }
   else if (dataID == 12) {
      //player.setFloor();
   }
   else if (dataID == 13) {
      //player.setScore();
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
