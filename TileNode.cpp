#include <iostream>
#include "TileNode.h"

TileNode::TileNode(Tile *tileData, TileNode *nextTileNode)
{
    this->tileData = tileData;
    this->nextTileNode = nextTileNode;
}

TileNode::~TileNode()
{
}

Tile *TileNode::getTileData()
{
    return this->tileData;
}

TileNode *TileNode::getNextTileNode()
{
    return this->nextTileNode;
}

void TileNode::setNextTileNode(TileNode *nextTileNode)
{
    this->nextTileNode = nextTileNode;
}

//We can use this to get a tile tostring once we've set up tile.cpp class
// std::string TileNode::getTileDataToString(Tile* tileData) {
//     std::string statement = tileData->tileToString();
//     return statement;
// }