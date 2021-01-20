#include "State.h"


State::State(int x, int y)
{
    symbol = 'A';
    this->x = x;
    this->y = y;
}

int State::GetX() const
{
    return x;
}

int State::GetY() const
{
    return y;
}

char State::GetSymbol() const
{
    return symbol;
}

bool State::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}