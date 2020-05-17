#ifndef TYPES_H
#define TYPES_H

#define NUM_FACTORIES 5
#define WALL_DIM 5
#define FLOOR_DIM 7

enum TileType {
   RED,
   YELLOW,
   DARK_BLUE,
   LIGHT_BLUE,
   BLACK,
   FIRST_PLAYER,
   NO_TILE
   };

enum Direction {
   VERTICAL,
   HORIZONTAL
};


#endif //TYPES_H