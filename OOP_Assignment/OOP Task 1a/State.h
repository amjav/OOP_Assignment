#pragma once

class State
{
	public:

      State() = default;
      State(int x, int y);
        
	  int GetX() const;
      int GetY() const;
      char GetSymbol() const;
      bool IsAtPosition(int x, int y);

  protected:
      // data members
      char symbol;
      int x, y;
};

