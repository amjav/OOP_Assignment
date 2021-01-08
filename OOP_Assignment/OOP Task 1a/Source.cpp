#include "raylib.h"
#include "Game.h"
#include "Levels.h"
#include "Source.h"

int main(){
    InitWindow(1000, 700, "OOP Assignment 1");
    //window size for grid and title of window
    SetTargetFPS(60);
    //framerate (FPS - Frames per second)

    //Tile Textures
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
        ClearBackground(WHITE);

        if (game.IsRunning())
        {
            

            if (IsKeyPressed(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyPressed(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            if (IsKeyPressed(KEY_UP))     game.ProcessInput(KEY_UP);
            if (IsKeyPressed(KEY_DOWN))   game.ProcessInput(KEY_DOWN);
            if (IsKeyPressed(X_KEY))      game.ProcessInput(X_KEY);

            game.CheckHole();
            game.CheckKey();
            game.CheckGate();

            

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

                    case PATH:
                    {
                            char s = NULL;

                            DrawTexture(TexPath, xPosition, yPosition, BEIGE);
                    
                            s = game.IsKeyCollectedCoord(x, y);

                            switch (s)
                            {
                                case 'y':  DrawTexture(TexKey, 710, 500, YELLOW); break;
                                case 'v':  DrawTexture(TexKey, 745, 500, PURPLE); break;
                                case 'r': DrawTexture(TexKey, 780, 500, PINK);    break;
                                case 'g': DrawTexture(TexKey, 815, 500, GOLD);    break;
                                case 'o':  DrawTexture(TexKey, 850, 500, ORANGE); break;
                                case 'd':  DrawTexture(TexKey, 885, 500, BLUE);   break;
                                case 'l':  DrawTexture(TexKey, 920, 500, LIME);   break;
                                case 'm': DrawTexture(TexKey, 955, 500, MAGENTA); break;
                                case 'e': DrawTexture(TexKey, 710, 535, RED); break;

                                default: break;
                            }

                        break; //break for the path case
                    }
                    case PLAYER:DrawTexture(Texmouse, xPosition, yPosition, GRAY);      break;
                    case HOLE:DrawTexture(Texhole, xPosition, yPosition, WHITE);        break;

                        //GATES                
                    case 'Y': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, YELLOW);
                            break; 
                        }
                    }
                    case 'R': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, PINK);
                            break;
                        }
                    }
                    case 'G': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, GOLD);
                            break;
                        }
                    }
                    case 'O': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, ORANGE);
                            break;
                        }
                    }
                    case 'D': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, BLUE);
                            break;
                        }
                    }
                    case 'L': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, LIME);
                            break;
                        }
                    }
                    case 'M': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, MAGENTA);
                            break;
                        }
                    }
                    case 'V': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, PURPLE);
                            break;
                        }
                    }

                    //KEYS

                    case 'y': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'y') {
                            DrawTexture(TexKey, 710, 500, DULLYELLOW);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, YELLOW);
                        break; 
                    }
                    case 'v': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'v') {
                            DrawTexture(TexKey, 745, 500, DULLPURPLE);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, PURPLE); 
                        break; 
                    }
                    case 'r': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'r') {
                            DrawTexture(TexKey, 780, 500, DULLPINK);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, PINK); 
                        break;
                    }
                    case 'g': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'g') {
                            DrawTexture(TexKey, 815, 500, DULLGOLD);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, GOLD);
                        break;
                    }
                    case 'o': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'g') {
                            DrawTexture(TexKey, 850, 500, DULLORANGE);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, ORANGE); 
                        break; 
                    }
                    case 'd': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'd') {
                            DrawTexture(TexKey, 885, 500, DULLBLUE);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, BLUE);
                        break;
                    }
                    case 'l': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'l') {
                            DrawTexture(TexKey, 920, 500, DULLLIME);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, LIME); 
                        break;
                    }
                    case 'm': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'm') {
                            DrawTexture(TexKey, 955, 500, DULLMAGENTA);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, MAGENTA);
                        break;
                    }
                    
                    //START + END
                    case START: DrawRectangle(xPosition, yPosition, cellSize, cellSize, GREEN);   break;
                    case 'E': {
                        if (game.CheckGate() == false) {

                            DrawTexture(TexGate, xPosition, yPosition, RED);
                            break;
                        }
                    }

                    //END KEY
                    case 'e': {
                        char f = game.IsKeyVecCheck(x, y);
                        if (f == 'e') {
                            DrawTexture(TexKey, 710, 535, DULLRED);
                        }
                        DrawTexture(TexKey, xPosition, yPosition, RED);                   
                        break; 
                    }

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