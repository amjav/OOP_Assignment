#include "Player.h"
#include "Levels.h"
#include "math.h"

Player::Player() : symbol(PLAYER), x(0), y(0), alive(true), escaped(false), dx(0), dy(0)
{
   // PositionAtStart();
}

int Player::GetX()
{
    return x;
}

int Player::GetY()
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}

void Player::SetAlive() {
 // alive =
}

bool Player::GetAlive()
{
    return alive;
}

void Player::SetEscaped() {
 // escaped =
}

bool Player:: GetEscaped() {

    
    return escaped;
}

bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::Move(int key)
{
    switch (key)
    {
        //maybe add in continuous move keys
    case KEY_LEFT:
        dx = -0.5;
        dy = 0;
        break;
    case KEY_RIGHT:
        dx = +0.5;
        dy = 0;
        break;
    case KEY_UP:
        dx = 0;
        dy = -0.5;
        break;
    case KEY_DOWN:
        dx = 0;
        dy = +0.5;
        break;
    default:
        // not a key we care about, so do nothing
        break;
    }

    // update mouse coordinates if move is possible
    if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        UpdatePosition(dx, dy);
    }
}

void Player::UpdatePosition(float dx, float dy)
{
   
    dxx += dx;
    dyy += dy;
    if (floor(dxx) == dxx)
    {
      x += dxx;
      dxx = 0;
      
    }
    if((floor(dyy) == dyy))
    {
      y += dyy;
      dyy = 0;
    }
 
}

void Player::HolePositionUpdate(int dx, int dy)
{
    x = dx;
    y = dy;
}

void Player::PositionAtStart()
{
    x = l1.GetStartX();
    y = l1.GetStartY();
    dxx = 0;
    dyy = 0;
}

