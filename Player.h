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

   void load(std::string data, int dataID);

   void setScore(int score);
   void setWall(PlayerWall* wall);
   void setName(std::string name);

   private:

   PlayerWall* wall;
   std::string playerName;
   int score;



};

#endif