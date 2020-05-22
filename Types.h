#ifndef TYPES_H
#define TYPES_H

#define NUM_FACTORIES 5
#define WALL_DIM 5
#define FLOOR_DIM 7
#define TILES_PER_FAC 4

enum class TileType {
   RED = 'R',
   YELLOW = 'Y',
   DARK_BLUE = 'B',
   LIGHT_BLUE = 'L',
   BLACK = 'U',
   FIRST_PLAYER = 'F',
   NO_TILE = '.'
   };

enum class Direction {
   VERTICAL = 'V',
   HORIZONTAL = 'H'
};


#endif //TYPES_H