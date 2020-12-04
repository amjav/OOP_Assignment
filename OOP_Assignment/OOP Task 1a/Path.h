#pragma once
#include <assert.h>
#include "constants.h"
using namespace std;

class Path
{
    public:
        // constructors
        Path() = default;
        Path(int x, int y);

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

