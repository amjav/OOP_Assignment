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
#include <string>


class Game
{
   public:
        void Setup();
        void CheckHole();
        bool CheckGate(int x, int y);
        void ProcessInput(int key);
        bool IsRunning();
        void CheckKey();
        vector<vector<char>> PrepareGrid();
        char IsKeyVecCheck(int x, int y);
        char IsKeyCollectedCoord(int x, int y);
        int GetCollectedKeysSize();
        bool CheckExitGate();
        void drawEndLevel();


      //to do: make player private and then create get set functiions.

      //made variables private
    private:
      Player player;
      Levels l1;
      Rectangle rec;
      string level = "level1.txt";
      string* levelPtr = &level;
};