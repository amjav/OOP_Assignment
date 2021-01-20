#pragma once
#include "State.h"

class Gate : public State
{
    public:
        // constructors
        Gate() = default;
        Gate(int x, int y, char sym);

};

