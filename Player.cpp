#include "Player.h"
#include <string>


Player::Player(std::string name) {
   this->playerName = name;
}

Player::~Player()
{


}


std::string Player::getName() {
   return playerName;
}

PlayerWall Player::getWall() {
   return this->wall;
}

int Player::getScore() {
   return this->score;
}

void Player::setScore(int score) {
   this->score = score;
}

void Player::setWall(PlayerWall wall) {
   this->wall = wall;
}
