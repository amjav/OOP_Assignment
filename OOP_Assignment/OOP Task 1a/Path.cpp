#include "Path.h"
#include "Constants.h"

//tile types may inlcude inheritence

Path::Path(int x, int y)
{
    symbol = PATH;
    this->x = x;
    this->y = y;
}
