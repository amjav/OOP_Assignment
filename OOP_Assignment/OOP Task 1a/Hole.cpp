#include "Hole.h"
#include "Constants.h"

//tile types may inlcude inheritence

Hole::Hole(int x, int y)
{
    symbol = HOLE;
    this->x = x;
    this->y = y;
}

