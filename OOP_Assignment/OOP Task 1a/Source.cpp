#include "raylib.h"
#include "Game.h"
#include "Levels.h"

int main()
{
    InitWindow(1000, 700, "OOP Assignment 1");
    //window size for grid and title of window
    SetTargetFPS(60);
    //framerate (FPS - Frames per second)
    Texture2D TexKey = LoadTexture("Key.png");
    Texture2D TexGate = LoadTexture("Gate.png");
    Texture2D Texmouse = LoadTexture("mouse.png");
    Texture2D Texhole = LoadTexture("hole.png");
    Texture2D TexPath = LoadTexture("Path.png");
    Texture2D TexCheese = LoadTexture("Cheese.png");
    Texture2D TexGrass = LoadTexture("Grass.png");


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


        for (int x = 0; x < SIZE; x++)
        {
            for (int y = 0; y < SIZE; y++)
            {
                int xPosition = x * cellSize;
                int yPosition = y * cellSize;

                switch (grid[y][x])
                {
                    case WALL:DrawTexture(TexGrass, xPosition, yPosition, GREEN);       break;
                    case PATH:DrawTexture(TexPath, xPosition, yPosition, BEIGE);        break;
                    case PLAYER:DrawTexture(Texmouse, xPosition, yPosition, GRAY);      break;
                    case HOLE:DrawTexture(Texhole, xPosition, yPosition, WHITE);        break;

                    //GATES                
                    case 'Y': DrawTexture(TexGate, xPosition, yPosition, YELLOW);      break;
                    case 'R': DrawTexture(TexGate, xPosition, yPosition, PINK);        break;
                    case 'G': DrawTexture(TexGate, xPosition, yPosition, GOLD);        break;
                    case 'O': DrawTexture(TexGate, xPosition, yPosition, ORANGE);      break;
                    case 'D': DrawTexture(TexGate, xPosition, yPosition, BLUE);        break;
                    case 'L': DrawTexture(TexGate, xPosition, yPosition, LIME);        break;
                    case 'M': DrawTexture(TexGate, xPosition, yPosition, MAGENTA);     break;
                    case 'V': DrawTexture(TexGate, xPosition, yPosition, PURPLE);      break;


                    //KEYS
                    case 'y': DrawTexture(TexKey, xPosition, yPosition, YELLOW);        break;
                    case 'v': DrawTexture(TexKey, xPosition, yPosition, PURPLE);        break;
                    case 'r': DrawTexture(TexKey, xPosition, yPosition, PINK);          break;
                    case 'g': DrawTexture(TexKey, xPosition, yPosition, GOLD);          break;
                    case 'o': DrawTexture(TexKey, xPosition, yPosition, ORANGE);        break;
                    case 'd': DrawTexture(TexKey, xPosition, yPosition, BLUE);          break;
                    case 'l': DrawTexture(TexKey, xPosition, yPosition, LIME);          break;
                    case 'm': DrawTexture(TexKey, xPosition, yPosition, MAGENTA);       break;


                    //START + END
                    case START: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);   break;
                    case 'E': DrawTexture(TexCheese, xPosition, yPosition, RED);                  break;
                    case 'e': DrawTexture(TexKey, xPosition, yPosition, RED);                     break;


                    default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
                }

                // draw lines around each tile, remove this if you don't like it!
                //DrawRectangleLines(x * cellSize, y * cellSize, cellSize, cellSize, DARKGRAY);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;



}