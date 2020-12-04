#include "Path.h"
#include "Constants.h"

//tile types may inlcude inheritence

Path::Path(int x, int y)
{
    symbol = PATH;
    this->x = x;
    this->y = y;
}

int Path::GetX()
{
    return x;
}

int Path::GetY()
{
    return y;
}

char Path::GetSymbol() const
{
    return symbol;
}

bool Path::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}