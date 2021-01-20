#pragma once

#include "constants.h"
#include "Levels.h"

class Player
{
    public:
        // constructor
        Player();

        // assessors
        int GetX();
        int GetY();
        char GetSymbol() const;
        bool GetAlive();
        bool GetEscaped();
        bool IsAtPosition(int x, int y);
        void UpdatePosition(float dx, float dy);
        void HolePositionUpdate(int dx, int dy);
        void PositionAtStart();
        //make const?

        // mutators
        void Move(int key);

        char symbol;

    private:
        // data members
        int  x, y;
        bool alive;
        bool escaped;
        float dx;
        float dy;
        float dxx;
        float dyy;
        Levels l1;

        // supporting functions 
        
        void SetAlive();
        void SetEscaped();
};