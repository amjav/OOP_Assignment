#include "Key.h"
#include "Constants.h"

//tile types may inlcude inheritence

//that we need to pass in the symbol as a parameter
Key::Key(int x, int y, char sym)
{
    symbol = sym;
    this->x = x;
    this->y = y;
}

int Key::GetX()
{
    return x;
}

int Key::GetY()
{
    return y;
}

char Key::GetSymbol() const
{
    return symbol;
}

bool Key::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}
