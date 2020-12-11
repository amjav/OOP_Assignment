#include "Keys.h"
#include "Constants.h"

//tile types may inlcude inheritence

//that we need to pass in the symbol as a parameter
Keys::Keys(int x, int y)
{
    symbol = KEYS;
    this->x = x;
    this->y = y;
}

int Keys::GetX()
{
    return x;
}

int Keys::GetY()
{
    return y;
}

char Keys::GetSymbol() const
{
    return symbol;
}

bool Keys::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}
