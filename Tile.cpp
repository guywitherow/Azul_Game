#include "Tile.h"

Tile::Tile(TileType type){

   this->type = type;

}

Tile::~Tile() {}

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

TileType Tile::getType() {
   return type;
}