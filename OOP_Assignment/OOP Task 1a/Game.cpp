#include "raylib.h"
#include "Game.h"
#include "Levels.h"

    void Game::Setup()
    {
        l1.CreateLevels();

        player.UpdatePosition(l1.GetStartX(), l1.GetStartY());


        //Get level which return the coordinates for the wall of the levels.

    }

   void Game :: CheckHole()
   {
      int playerX = player.GetX();
      int playerY = player.GetY();

      if (l1.IsHoleAtPosition(playerX, playerY) == true)
      {
        DrawText("Press X to jump in hole", 750, 650, 18, WHITE);
      }

   }

   void Game ::  CheckKey()
   {
       int playerX = player.GetX();
       int playerY = player.GetY();


       if (l1.IsKeyAtPosition(playerX, playerY) != 0 )
       {
           for (int i = 0; i < l1.Keys.size(); i++)
           {
              
                   if (l1.Keys[i].IsAtPosition(playerX, playerY))
                   {
                       l1.CollectedKeys.push_back(l1.Keys[i]);
                       l1.Keys.erase(l1.Keys.begin() + i);
                       
                   }
               
           }
       }

   }

   char Game :: IsKeyCollectedCoord(int x, int y)
   {
     for (int i = 0; i < l1.CollectedKeys.size(); i++)
     
     {
        if(x == l1.CollectedKeys[i].GetX() && y == l1.CollectedKeys[i].GetY())
        {
            return l1.CollectedKeys[i].GetSymbol();
            
        }
        else
        {
            return 0;
        }
        
     }
   } 

   char Game :: IsKeyVecCheck(int x, int y)
   {
      for (int i = 0; i < l1.Keys.size(); i++)
     
     {
        if(x == l1.Keys[i].GetX() && y == l1.Keys[i].GetY())
        {
            return l1.Keys[i].GetSymbol();
            
        }
        
        
     } 
      
        return 0;
        
   }

   int Game :: GetCollectedKeysSize()
   {
       return l1.CollectedKeys.size();
   }

   void Game::ProcessInput(int key)
    {
       int x = player.GetX();
       int y = player.GetY();
       int hX = 0;
       int hY = 0;


       if (key == KEY_LEFT)
       {
           int leftX = x - 1;
           int leftY = y;
           if (l1.IsWallAtPosition(leftX, leftY) == false)
           {
               player.Move(key);
           }
       }

       if(key == KEY_RIGHT){

           int rightX = x + 1;
           int rightY = y;

           if (l1.IsWallAtPosition(rightX, rightY) == false)
           {
               player.Move(key);
           }
           
       }

       if (key == KEY_UP)
       {
           int upY = y - 1;
           int upX = x;

           if (l1.IsWallAtPosition(upX, upY) == false)
           {
               player.Move(key);
           }
       }

       if (key == KEY_DOWN){
           int downY = y + 1;
           int downX = x;

           if (l1.IsWallAtPosition(downX, downY) == false)
           {
               player.Move(key);
           }

       }

       if(key == X_KEY)
       {
           int pX = player.GetX();
           int pY = player.GetY();

           for (int i= 0 ; i < l1.holes.size(); i++)
           {
               if( l1.holes[i].GetX() != pX && l1.holes[i].GetY() != pY)
               {
                   hX = l1.holes[i].GetX();
                   hY = l1.holes[i].GetY();
               }

           }

           if (l1.IsHoleAtPosition(pX,pY) == true)
           {
               
              player.HolePositionUpdate(hX,hY);
               
           }

       }

       

    }

    /// <summary>
    /// This function builds up a 2D grid of characters representing the current state of the game.
    /// The characters are later used to decide which colour sqaure to display, but you could display images instead.
    ///     maybe use emojis 
    /// </summary>

    vector<vector<char>> Game::PrepareGrid()
    {
        // create the 2D grid
        vector<vector<char>> grid;

        // for each row
        for (int row = 0; row < SIZE; ++row)
        {
            // create the inner vector to add to the 2D grid
            vector<char> line;

            // for each column, work out what's in that position and add the relevant char to the 2D grid
            for (int col = 0; col < SIZE; ++col)
            {
                if (row == player.GetY() && col == player.GetX())
                {
                    line.push_back(player.GetSymbol());
                }
                else if (l1.IsWallAtPosition(col, row))
                {
                    line.push_back(WALL);
                }
                else if (l1.IsPathAtPosition(col, row))
                {
                    line.push_back(PATH);
                }
                else if (l1.IsHoleAtPosition(col, row)) 
                {
                    line.push_back(HOLE);
                }
                else if (l1.IsKeyAtPosition(col, row) != 0) 
                {
                    line.push_back(l1.IsKeyAtPosition(col, row));
                }
                else if (l1.IsGateAtPosition(col, row) != 0) 
                {
                    line.push_back(l1.IsGateAtPosition(col, row));
                }
                else
                {
                    line.push_back(PATH);
                }

            }

            assert(line.size() == SIZE);
            // now that the row is full, add it to the 2D grid
            grid.push_back(line);
        }

        return grid;
    }

    

    bool Game::IsRunning()
    {
        // depending on your game you'll need to modify this to return false
        // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!
        return true;
    }