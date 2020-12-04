#pragma once
class Keys
{

	public:
    // constructors
    Keys() = default;
    Keys(int x, int y);

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

