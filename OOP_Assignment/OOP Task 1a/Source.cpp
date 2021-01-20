#include "raylib.h"
#include "Game.h"
#include "Levels.h"
#include "Source.h"

int main(){

  int screenwidth = 1000;
  int screenheight = 700;
  InitWindow(screenwidth, screenheight, "OOP Assignment 1");
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
    
    
    int finishtime;

    game.Setup();
    //setting up game object

    

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (game.IsRunning())
        {
            

            if (IsKeyDown(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyDown(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            if (IsKeyDown(KEY_UP))     game.ProcessInput(KEY_UP);
            if (IsKeyDown(KEY_DOWN))   game.ProcessInput(KEY_DOWN);
            if (IsKeyPressed(X_KEY))   game.ProcessInput(X_KEY);
            

            game.CheckHole();
            game.CheckKey();
            
            //game.CheckGate();
            
            


        }

        else
        {
            

            //DrawText("TODO: Why did the game end?", 610, 10, 20, LIGHTGRAY);
            if (IsKeyPressed(KEY_YES))    game.ProcessInput(KEY_YES);
            if (IsKeyPressed(KEY_NO))     game.ProcessInput(KEY_NO);

            
        }

        // this is 35, unless you change the window size (don't change the window size)
        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));
        //Allows grid to expand to the size of the window



        if (game.CheckExitGate() == 0)
        {
          
          int timer = game.GetTimer().GetDuration();
         
          string t = to_string(timer);

          string a = "00:" + t;

          const char* tnum = a.c_str();

          if (timer < 60)
          {
            if (timer < 10)
            {
              string b = "00:0" + t;

              tnum = b.c_str();

              DrawText(tnum, 815, 50, 40, BLUE);
            }
            else
            {
              DrawText(tnum, 815, 50, 40, BLUE);
            }

          }
          else if (timer >= 60)
          {
            int mins = timer / 60;
            int secs = timer - (mins * 60);

            string m = to_string(mins);
            string s = to_string(secs);
            string minandsecs;
            if (secs < 10)
            {
              minandsecs = m + ":0" + s ;
            }
            else 
            {
              minandsecs = m + ":" + s;
            }
            const char* time = minandsecs.c_str();

            DrawText(time, 815, 50, 40, BLUE);

          }

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

                DrawTexture(TexGate, xPosition, yPosition, YELLOW);
                break;

              }
              case 'R': {


                DrawTexture(TexGate, xPosition, yPosition, PINK);
                break;

              }
              case 'G': {


                DrawTexture(TexGate, xPosition, yPosition, GOLD);
                break;

              }
              case 'O': {


                DrawTexture(TexGate, xPosition, yPosition, ORANGE);
                break;

              }
              case 'D': {


                DrawTexture(TexGate, xPosition, yPosition, BLUE);
                break;

              }
              case 'L': {


                DrawTexture(TexGate, xPosition, yPosition, LIME);
                break;

              }
              case 'M': {


                DrawTexture(TexGate, xPosition, yPosition, MAGENTA);
                break;

              }
              case 'V': {


                DrawTexture(TexGate, xPosition, yPosition, PURPLE);
                break;

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

                DrawTexture(TexGate, xPosition, yPosition, RED);
                break;

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
        }
        else
        {
          //Rectangle r = { (screenwidth/2)-250,(screenheight/2) - 100,screenwidth - 500,screenheight - 500 };
          

          const char* endtxt1 = "Congrats! you have collected all the keys and opened all the gates!";
          const char* endtxt2 = "Press[Y] to continue to next level or [N] to exit game!";
          const char* endtxt3 = "Press[Y] to play again or [N] to exit game!";
          //DrawTextRec(GetFontDefault(),endtxt,r,18,2,true,RED);
          int m1 = MeasureText(endtxt1, 18);
          int m2 = MeasureText(endtxt2, 18);
          int m3 = MeasureText(endtxt3, 18);
          Vector2 fontPosition1 = { (screenwidth / 2) - (m1/2),(screenheight / 2) - 50 };
          Vector2 fontPosition2 = { (screenwidth / 2) - (m2 / 2),(screenheight / 2) - 20 };
          Vector2 fontPosition3 = { (screenwidth / 2) - (m3 / 2),(screenheight / 2) - 20 };

          if (game.CheckEndGame() == true)
          {
            DrawTextEx(GetFontDefault(), endtxt1, fontPosition1, 18, 2, RED);
            DrawTextEx(GetFontDefault(), endtxt3, fontPosition3, 18, 2, GRAY);
          }
          else
          {
            DrawTextEx(GetFontDefault(), endtxt1, fontPosition1, 18, 2, RED);
            DrawTextEx(GetFontDefault(), endtxt2, fontPosition2, 18, 2, GRAY);
          }
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;



}