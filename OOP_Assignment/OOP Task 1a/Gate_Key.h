#pragma once
class Gate_Key
{
public:
    // constructors
    Gate_Key() = default;
    Gate_Key(int x, int y);

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

