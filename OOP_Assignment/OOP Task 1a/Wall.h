#pragma once

#include <assert.h>
#include "constants.h"
#include "State.h"

using namespace std;

class Wall : public State
{
    public:
       // constructors
       Wall() = default;
       Wall(int x, int y);

};