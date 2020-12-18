#pragma once
class Gate
{
    public:
        // constructors
        Gate() = default;
        Gate(int x, int y, char sym);

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

