#include "Gate_Key.h"
#include "Constants.h"

Gate_Key::Gate_Key(int x, int y)
{
    symbol = GATE;
    this->x = x;
    this->y = y;
}

int Gate_Key::GetX()
{
    return x;
}

int Gate_Key::GetY()
{
    return y;
}

char Gate_Key::GetSymbol() const
{
    return symbol;
}

bool Gate_Key::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}