#include "Tile.h"

Tile::Tile() {
    this->type = TileType::NO_TILE;
}

Tile::Tile(TileType type){
   this->type = type;
}

Tile::~Tile() {
   //tile only has tiletype which is a char, automaticlly deleted
}

std::string Tile::tileToString() {
   std::string typeString;
   if (type == TileType::RED) {
      typeString = "Red";
   }
   else if (type == TileType::YELLOW) {
      typeString = "Yellow";
   }
   else if (type == TileType::LIGHT_BLUE) {
      typeString = "Light Blue";
   }
   else if (type == TileType::DARK_BLUE) {
      typeString = "Dark Blue";
   }
   else if (type == TileType::BLACK) {
      typeString = "Black";
   }
   else if (type == TileType::NO_TILE) {
      typeString = "No Tile";
   }
   else if (type == TileType::FIRST_PLAYER) {
      typeString = "First Player Tile";
   }
   return typeString;
}

char Tile::tileToChar() {
   char typeChar = ' ';
   if (type == TileType::RED) {
      typeChar = 'R';
   }
   else if (type == TileType::YELLOW) {
      typeChar = 'Y';
   }
   else if (type == TileType::LIGHT_BLUE) {
      typeChar = 'L';
   }
   else if (type == TileType::DARK_BLUE) {
      typeChar = 'B';
   }
   else if (type == TileType::BLACK) {
      typeChar = 'U';
   }
   else if (type == TileType::NO_TILE) {
      typeChar = '.';
   }
   else if (type == TileType::FIRST_PLAYER) {
      typeChar = 'F';
   }
   return typeChar;
}

TileType Tile::getType() {
   return type;
}
