#include "Hole.h"
#include "Constants.h"

//tile types may inlcude inheritence

Hole::Hole(int x, int y)
{
    symbol = HOLE;
    this->x = x;
    this->y = y;
}

int Hole::GetX()
{
    return x;
}

int Hole::GetY()
{
    return y;
}

char Hole::GetSymbol() const
{
    return symbol;
}

bool Hole::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}
