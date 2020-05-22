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


std::string Player::getName() {
   return playerName;
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
