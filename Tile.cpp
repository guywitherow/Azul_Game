#include "Tile.h"

Tile::Tile(TileType type){
   this->type = type;
}

Tile::~Tile() {
   //tile only has tiletype which is a char, automaticlly deleted
}

std::string Tile::tileToString() {
   std::string typeString;
   if (type == RED) {
      typeString = "Red";
   }
   else if (type == YELLOW) {
      typeString = "Yellow";
   }
   else if (type == LIGHT_BLUE) {
      typeString = "Light Blue";
   }
   else if (type == DARK_BLUE) {
      typeString = "Dark Blue";
   }
   else if (type == BLACK) {
      typeString = "Black";
   }
   else if (type == NO_TILE) {
      typeString = "No Tile";
   }
   else if (type == FIRST_PLAYER) {
      typeString = "First Player Tile";
   }
   return typeString;
}

char Tile::tileToChar() {
   char typeChar = ' ';
   if (type == RED) {
      typeChar = 'R';
   }
   else if (type == YELLOW) {
      typeChar = 'Y';
   }
   else if (type == LIGHT_BLUE) {
      typeChar = 'L';
   }
   else if (type == DARK_BLUE) {
      typeChar = 'B';
   }
   else if (type == BLACK) {
      typeChar = 'U';
   }
   else if (type == NO_TILE) {
      typeChar = '.';
   }
   else if (type == FIRST_PLAYER) {
      typeChar = 'F';
   }
   return typeChar;
}

TileType Tile::getType() {
   return type;
}
