#include "Game.h"
#include "Levels.h"

    void Game::Setup()
    {
        //created white wall blocks however player can still run through them currently
        /*walls.push_back(Wall(4, 7));
        walls.push_back(Wall(9, 15));
        walls.push_back(Wall(15, 4));*/

        
        l1.CreateLevels();


        //Get level which return the coordinates for the wall of the levels.

    }

   void Game::ProcessInput(int key)
    {
        player.Move(key);
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