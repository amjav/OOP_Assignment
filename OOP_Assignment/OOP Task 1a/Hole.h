#pragma once
#include <assert.h>
#include "constants.h"
#include "State.h"
using namespace std;

class Hole : public State
{
    public:
        // constructors
        Hole() = default;
        Hole(int x, int y);

};



