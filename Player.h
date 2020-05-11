#include "PlayerWall.h"
#include "Tile.h"

class Player {

 public:
      Player(std::string name);
      ~Player();

      void shuffle();

      Tile getTopTile();

   private:

      PlayerWall wall;



};