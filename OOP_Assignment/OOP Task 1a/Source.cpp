#include "raylib.h"
#include "Game.h"
#include "Levels.h"

int main()
{
    InitWindow(1000, 700, "OOP Assignment 1");
    //window size for grid and title of window
    SetTargetFPS(60);
    //framerate (FPS - Frames per second)

    Game game;
    //creating a game object
    game.Setup();
    //setting up game object

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKGRAY);

        if (game.IsRunning())
        {
            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP);
            if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN);
        }
        else
        {
            DrawText("TODO: Why did the game end?", 610, 10, 20, LIGHTGRAY);
        }

        // this is 35, unless you change the window size (don't change the window size)
        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));
        //Allows grid to expand to the size of the window

        const auto grid = game.PrepareGrid();

        Texture2D TexKey = LoadTexture("OOP Task 1a\Key");

        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (grid[y][x])
                {
                    case PATH:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, SKYBLUE);  break;
                    case WALL:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BROWN);    break;
                    case PLAYER: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);    break;
                    case HOLE:   DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLACK);    break;

                    //GATES
                    case 'Y': DrawTexture(TexKey, xPosition, yPosition, YELLOW);
                    //case 'Y': DrawRectangle(xPosition, yPosition, cellSize, cellSize, YELLOW);  break;
                    case 'V': DrawRectangle(xPosition, yPosition, cellSize, cellSize, PURPLE);  break;
                    case 'R': DrawRectangle(xPosition, yPosition, cellSize, cellSize, PINK);    break;
                    case 'G': DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);    break;
                    case 'O': DrawRectangle(xPosition, yPosition, cellSize, cellSize, ORANGE);  break;
                    case 'D': DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE);    break;
                    case 'L': DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIME);    break;
                    case 'M': DrawRectangle(xPosition, yPosition, cellSize, cellSize, MAGENTA); break;

                    //KEYS
                    case 'y': DrawRectangle(xPosition, yPosition, cellSize, cellSize, YELLOW);  break;
                    case 'v': DrawRectangle(xPosition, yPosition, cellSize, cellSize, PURPLE);  break;
                    case 'r': DrawRectangle(xPosition, yPosition, cellSize, cellSize, PINK);    break;
                    case 'g': DrawRectangle(xPosition, yPosition, cellSize, cellSize, GOLD);    break;
                    case 'o': DrawRectangle(xPosition, yPosition, cellSize, cellSize, ORANGE);  break;
                    case 'd': DrawRectangle(xPosition, yPosition, cellSize, cellSize, BLUE);    break;
                    case 'l': DrawRectangle(xPosition, yPosition, cellSize, cellSize, LIME);    break;
                    case 'm': DrawRectangle(xPosition, yPosition, cellSize, cellSize, MAGENTA); break;

                    //START + END
                    case START: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);   break;
                    case END: DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;
                    case 'e': DrawRectangle(xPosition, yPosition, cellSize, cellSize, RED);       break;


                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
                DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;



}