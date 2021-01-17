#include "Wall.h"

//tile types may inlcude inheritence

Wall::Wall(int x, int y)
{
    symbol = WALL;
    this->x = x;
    this->y = y;
}

