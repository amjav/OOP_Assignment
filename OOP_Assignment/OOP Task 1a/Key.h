#pragma once
class Key
{

	public:
    // constructors
    Key() = default;
    Key(int x, int y, char sym);

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
