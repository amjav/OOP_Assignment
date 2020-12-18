#include "Gate.h"
#include "Constants.h"

Gate::Gate(int x, int y, char sym)
{
    symbol = sym;
    this->x = x;
    this->y = y;
}

int Gate::GetX()
{
    return x;
}

int Gate::GetY()
{
    return y;
}

char Gate::GetSymbol() const
{
    return symbol;
}

bool Gate::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}