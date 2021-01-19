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
        void UpdatePosition(int dx, int dy);
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
        int dx;
        int dy;
        Levels l1;

        // supporting functions 
        
        void SetAlive();
        void SetEscaped();
};