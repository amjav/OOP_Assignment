#pragma once

#include "constants.h"

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

        // supporting functions 
        void PositionInMiddleOfGrid();
        void UpdatePosition(int dx, int dy);
        void SetAlive();
        void SetEscaped();
};