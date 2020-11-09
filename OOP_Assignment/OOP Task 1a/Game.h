#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"

using namespace std;

class Game
{
   public:
      void Setup();
      void ProcessInput(int key);
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      vector<vector<char>> PrepareGrid();
      //to do: make player private and then create get set functiions.

      //made variables private
    private:
      Player player;
      vector<Wall> walls;
     
};