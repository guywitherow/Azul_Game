#ifndef PLAYER_H
#define PLAYER_H

#include "PlayerWall.h"
#include "Tile.h"
#include <string>

class Player {

   public:
   Player(std::string name);
   ~Player();

   std::string getName();
   PlayerWall* getWall();
   int getScore();

   void setScore(int score);
   void setWall(PlayerWall* wall);

   private:

   PlayerWall* wall;
   std::string playerName;
   int score;



};

#endif