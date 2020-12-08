#pragma once

#include <assert.h>	
#include <string>		
#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Keys.h"
#include "Gate.h"
#include "Path.h"

using namespace std;

class Game
{
   public:
      void Setup();
      void AddWall(int i, int j);
      void ProcessInput(int key);
      bool IsRunning();
      bool IsWallAtPosition(int x, int y);
      vector<vector<char>> PrepareGrid();

      vector<Wall> walls;
      vector<Keys> keys;
      vector<Gate> gate;
      vector<Path> path;
      

      //to do: make player private and then create get set functiions.

      //made variables private
    private:
      Player player;

     
};