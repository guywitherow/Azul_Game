
#include <iostream>
#include <string>


class Tile {
public:
//Tile constructor 
 Tile();

//Deconstructor
~Tile();

//clear function used in Deconstructor
void tileClear();

//Returns a toString of the Tile
 std::string tileToString();

 
};