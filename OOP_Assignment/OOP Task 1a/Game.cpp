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

        //cleared for start of next level or new game.
        l1.clearVectors();

        //level is created by passing in level type as a parameter.
        l1.CreateLevels(level);

        player.PositionAtStart();

        //player position updated to the start position.
        player.UpdatePosition(l1.GetStartX(), l1.GetStartY());


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

   bool Game::CheckGate(int &x, int &y)
   {
      
       if (l1.IsGateAtPosition(x, y) != 0)
       {
           //both vectors are looped through to find a match between both.
           for (int i = 0; i < l1.gate.size(); i++) {
               for (int j = 0; j < l1.CollectedKeys.size(); j++) {

                   char s = l1.gate[i].GetSymbol();

                   //change s variable to a capital so it is comparable to a symbol of a gate.
                   if ((s + 32) == l1.CollectedKeys[j].GetSymbol() && l1.gate[i].GetX() == x && l1.gate[i].GetY() == y ) {

                       SetSoundVolume(openGate, 1);
                       PlaySound(openGate);

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
              //check that a key is within the stated position taken by the players current position.
              if (l1.Keys[i].IsAtPosition(playerX, playerY))
              {
                  //key is removed from keys vector but added to collectedkeys so that it can be compared
                  //with a gate. so the gate can be removed from the path.
                  l1.CollectedKeys.push_back(l1.Keys[i]);
                  l1.Keys.erase(l1.Keys.begin() + i);
                  SetSoundVolume(collectingKey, 0.6);
                  PlaySound(collectingKey);                 
              }
               
           }
       }

   }

   char Game :: IsKeyCollectedCoord(int &x, int &y)
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

   char Game :: IsKeyVecCheck(int &x, int &y)
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

   int Game :: GetCollectedKeysSize() const
   {
       return l1.CollectedKeys.size();
   }

   void Game::ProcessInput(int key)
    {
       int x = player.GetX();
       int y = player.GetY();
       int hX = 0;
       int hY = 0;
       
         //if statements to check positions around the player and apply any rules necessary so they are unable 
         //to step through a gate or path
         if (key == KEY_LEFT)
         {

           int leftX = x - 1;
           int leftY = y;

           CheckGate(leftX, leftY);

           if (l1.IsWallAtPosition(leftX, leftY) == false && l1.IsGateAtPosition(leftX, leftY) == 0)
           {
             player.Move(key);
             SetSoundVolume(bounce, 0.2);
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
             SetSoundVolume(bounce, 0.2);
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
             SetSoundVolume(bounce, 0.2);
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
             SetSoundVolume(bounce, 0.2);
             PlaySound(bounce);

           }
         }

         //x key pressed player is moved to the next hole position.
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

               SetSoundVolume(jumpingHole, 1);
               PlaySound(jumpingHole);

             }

           }

           if (l1.IsHoleAtPosition(pX, pY) == true)
           {

             player.HolePositionUpdate(hX, hY);

           }

         }

         //end of game/level options. moves to the next level or ends the game by checking the level that has been ran 
         //by looking at what is stored in *levelPtr.
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
             exit(0);
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
                    //if no other state is selected for the grid square it is defaulted to a path
                    line.push_back(PATH);
                }

            }

            assert(line.size() == SIZE);
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
          MyFile.close();
         return true;
      }
      else
      {
        return false;
      }

    }

    void Game::Saveleveltime(int &time)
    {
        string t = to_string(time);

        MyFile.open("score.txt");

        //if statement which checks the level in which the player is on.
           if (*levelPtr == "level1.txt") {
           
            //the score is then stored in a string and then writen onto the score.txt file.
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
 
    }

    Timer Game::GetTimer() const
    {
      return T;
    }

    bool Game::IsRunning()
    {
        if(l1.gate.size() == 1)
        {
             SetSoundVolume(passingLevel, 0.5);
             PlaySound(passingLevel);
            
              if (FinishTime == NULL)
              {
               //time is retuned as to when the player has reached the last gate in the level.
                FinishTime = T.GetDuration();
                Saveleveltime(FinishTime);
              }
            return false;    
        }
        else{
            return true;
        }
    }