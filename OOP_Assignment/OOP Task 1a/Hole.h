#pragma once
#include <assert.h>
#include "constants.h"
using namespace std;

class Hole
{
    public:
        // constructors
        Hole() = default;
        Hole(int x, int y);

        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);

    private:
        // data members
        char symbol;
        int x, y;
        //initialise or remove empty constructor.
};



