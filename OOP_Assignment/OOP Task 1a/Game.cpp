#include "raylib.h"
#include "Game.h"
#include "Levels.h"
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include <fstream>




    void Game::Setup()
    {
        FinishTime = NULL;

        T.Start();

        l1.clearVectors();

        l1.CreateLevels(level);

        player.PositionAtStart();

        player.UpdatePosition(l1.GetStartX(), l1.GetStartY());

        
        //Get level which return the coordinates for the wall of the levels.

    }

   void Game :: CheckHole()
   {
      int playerX = player.GetX();
      int playerY = player.GetY();

      if (l1.IsHoleAtPosition(playerX, playerY) == true)
      {
        DrawText("Press X to jump in hole", 750, 650, 18, BLACK);
      }

   }

   bool Game::CheckGate(int x, int y)
   {
       //CheckExitGate();

       if (l1.IsGateAtPosition(x, y) != 0)
       {
           
           for (int i = 0; i < l1.gate.size(); i++) {
               for (int j = 0; j < l1.CollectedKeys.size(); j++) {

                   char s = l1.gate[i].GetSymbol();

                   if ((s + 32) == l1.CollectedKeys[j].GetSymbol() && l1.gate[i].GetX() == x && l1.gate[i].GetY() == y ) {
                      
                       //void PlaySound(Sound sound); 
                       l1.gate.erase(l1.gate.begin() + i);
                       return true;
                   }
               }

            }

           return false;
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
                  //void PlaySound(Sound sound); 
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
     }   
     return 0;   
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

           CheckGate(leftX, leftY);

           if (l1.IsWallAtPosition(leftX, leftY) == false && l1.IsGateAtPosition(leftX, leftY) == 0)
           {
             player.Move(key);
             PlaySound(bounce);
           }
         }

         if (key == KEY_RIGHT) {

           int rightX = x + 1;
           int rightY = y;

           CheckGate(rightX, rightY);

           if (l1.IsWallAtPosition(rightX, rightY) == false && l1.IsGateAtPosition(rightX, rightY) == 0)
           {
             player.Move(key);
             PlaySound(bounce);

           }

         }

         if (key == KEY_UP)
         {
           int upY = y - 1;
           int upX = x;

           CheckGate(upX, upY);

           if (l1.IsWallAtPosition(upX, upY) == false && l1.IsGateAtPosition(upX, upY) == 0)
           {
             player.Move(key);
             PlaySound(bounce);

           }
         }

         if (key == KEY_DOWN) {
           int downY = y + 1;
           int downX = x;

           CheckGate(downX, downY);

           if (l1.IsWallAtPosition(downX, downY) == false && l1.IsGateAtPosition(downX, downY) == 0)
           {
             player.Move(key);
             PlaySound(bounce);

           }
         }

         if (key == X_KEY)
         {
           int pX = player.GetX();
           int pY = player.GetY();

           for (int i = 0; i < l1.holes.size(); i++)
           {
             if ((l1.holes[i].GetX() != pX && l1.holes[i].GetY() != pY) || (l1.holes[i].GetX() == pX && l1.holes[i].GetY() != pY) || (l1.holes[i].GetX() != pX && l1.holes[i].GetY() == pY))
             {
               hX = l1.holes[i].GetX();
               hY = l1.holes[i].GetY();
             }

           }

           if (l1.IsHoleAtPosition(pX, pY) == true)
           {

             player.HolePositionUpdate(hX, hY);

           }

         }


         if (key == KEY_YES) {

           if (CheckExitGate() == true)
           {
             if (*levelPtr == "level1.txt") {
               *levelPtr = "level2.txt";
             }
             else if (*levelPtr == "level2.txt") {
               *levelPtr = "level3.txt";
             }
             else if (*levelPtr == "level3.txt")
             {
               *levelPtr = "level1.txt";
             }

             Setup();
             
             
           }
         }



         if (key == KEY_NO) {

           if (CheckExitGate() == true)
           {
             CloseWindow();
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

    bool Game :: CheckExitGate()
    {
       
       if(l1.gate.size() == 1)
       {
           
            
         
           return true;
       }
        return 0;
    }

    bool Game::CheckEndGame()
    {
      if (*levelPtr == "level3.txt")
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    void Game::Saveleveltime(int time)
    {
        string t = to_string(time);

        MyFile.open("score.txt");

           if (*levelPtr == "level1.txt") {
           
             string l = "LEVEL 1: Time - " + t;
             MyFile << l;
                
           }
           else if (*levelPtr == "level2.txt") 
           {
             string l = "LEVEL 2: Time - " + t;

             MyFile << l;
           }
           else if (*levelPtr == "level3.txt")
           {
             string l = "LEVEL 3: Time - " + t;

             MyFile << l;
             
           }  
           
           MyFile.close();
    }

    Timer Game::GetTimer()
    {
      return T;
    }

    bool Game::IsRunning()
    {
        // depending on your game you'll need to modify this to return false
        // maybe it's when the player runs out of moves, maybe it's when they get caught, it's up to you!

        if(l1.gate.size() == 1)
        {
            
              if (FinishTime == NULL)
              {
                FinishTime = T.GetDuration();
                Saveleveltime(FinishTime);
              }
            return false;
            
        }
        else{

            
            return true;

        }
    }