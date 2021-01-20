#include "Player.h"
#include "Levels.h"
#include "math.h"

Player::Player() : symbol(PLAYER), x(0), y(0), dx(0), dy(0), dxx(0), dyy(0)
{
   
}

int Player::GetX() const
{
    return x;
}

int Player::GetY() const
{
    return y;
}

char Player::GetSymbol() const
{
    return symbol;
}

//used to determine the position of the player
bool Player::IsAtPosition(int x, int y)
{
    return this->x == x && this->y == y;
}

void Player::Move(int key)
{  
  //used to determine direction of the player depending on the different key inputs.
    switch (key)
    {
        
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
        break;
    }

    // used to update mouse coordinates if move is possible
    if (((x + dx) >= 1) && ((x + dx) <= SIZE) && ((y + dy) >= 1) && ((y + dy) <= SIZE))
    {
        UpdatePosition(dx, dy);
    }
}

//used to update the position of the player after each move
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

//used to determine the position of the hole
void Player::HolePositionUpdate(int dx, int dy)
{
    x = dx;
    y = dy;
}

//used to position the player at the start square at the begining of each level
void Player::PositionAtStart()
{
    x = l1.GetStartX();
    y = l1.GetStartY();
    dxx = 0;
    dyy = 0;
}

