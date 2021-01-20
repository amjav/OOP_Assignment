#pragma once

#include "constants.h"
#include "Levels.h"

class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX() const;
        int GetY() const;
        char GetSymbol() const;
        bool IsAtPosition(int x, int y);
        void UpdatePosition(float dx, float dy);
        void HolePositionUpdate(int dx, int dy);
        void PositionAtStart();
        
 
        // mutators
        void Move(int key);
        

    private:
        // data members
        char symbol;
        int  x, y;
        float dx;
        float dy;
        float dxx = 0;
        float dyy = 0;
        Levels l1;     
};