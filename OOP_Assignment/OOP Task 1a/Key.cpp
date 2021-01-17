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

