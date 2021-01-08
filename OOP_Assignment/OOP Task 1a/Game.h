#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Levels.h"
#include "Player.h"
#include "Wall.h"
#include "Key.h"
#include "Gate.h"
#include "Path.h"


class Game
{
   public:
      void Setup();
      void CheckHole();
      void ProcessInput(int key);
      bool IsRunning();
      void CheckKey();
      vector<vector<char>> PrepareGrid();
      char IsKeyVecCheck(int x, int y);
      char IsKeyCollectedCoord(int x, int y);
      int GetCollectedKeysSize();
      bool CheckGate();

      //to do: make player private and then create get set functiions.

      //made variables private
    private:
      Player player;
      Levels l1;

};