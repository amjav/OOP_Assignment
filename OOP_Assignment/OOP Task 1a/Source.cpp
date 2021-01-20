#include "raylib.h"
#include "Game.h"
#include "Source.h"

int main(){

  int screenwidth = 1000;
  int screenheight = 700;
  InitWindow(screenwidth, screenheight, "OOP Assignment 1");

  InitAudioDevice();
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


        //Used to run different keypress functions depending game state
        if (game.IsRunning())
        {
            

            if (IsKeyDown(KEY_RIGHT))  game.ProcessInput(KEY_RIGHT);
            if (IsKeyDown(KEY_LEFT))   game.ProcessInput(KEY_LEFT);
            if (IsKeyDown(KEY_UP))     game.ProcessInput(KEY_UP);
            if (IsKeyDown(KEY_DOWN))   game.ProcessInput(KEY_DOWN);
            if (IsKeyPressed(X_KEY))   game.ProcessInput(X_KEY);
            
            //Checks if hole is at player position to determind whether to give to option to press the X key or not
            game.CheckHole();
            //Checks if key is at the player position so that any keys collected can be moved 
            //to the collected keys vector and displayed on the right side of the screen
            game.CheckKey();
            
        }

        else
        {
            // Key pressed set up for end screen of each level and end screen of the game so the player can decided what to do   
            if (IsKeyPressed(KEY_YES))    game.ProcessInput(KEY_YES);
            if (IsKeyPressed(KEY_NO))     game.ProcessInput(KEY_NO);          
        }

        
        const int cellSize = (int)((float)GetScreenHeight() / (float)(SIZE));



        //Checks if all gates have been collected (except the start) so that the level can end
        if (game.CheckExitGate() == 0)
        {

            DrawText("Key Collection:", 735, 450, 30, BLUE);

          // Set up of timer so that is can be formatted and displayed while each level is running
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
          //grid is prepared so that the textures can be applied
          const auto grid = game.PrepareGrid();


          for (int x = 0; x < SIZE; x++)
          {
            for (int y = 0; y < SIZE; y++)
            {

              int xPosition = x * cellSize;
              int yPosition = y * cellSize;

              // switch case applies the textures to the correct squares depending on the symbol found in the level text file
              switch (grid[y][x])
              {
              case WALL:DrawTexture(TexGrass, xPosition, yPosition, GREEN);       break;

              case PATH:
              {
                char s = NULL;

                DrawTexture(TexPath, xPosition, yPosition, BEIGE);

                s = game.IsKeyCollectedCoord(x, y);
               // this is so that the collected keys are displayed on the right side of the screen
                switch (s)
                {
                case 'y':  DrawTexture(TexKey, 797.5, 500, YELLOW); break;
                case 'v':  DrawTexture(TexKey, 832.5, 500, PURPLE); break;
                case 'r': DrawTexture(TexKey, 867.5, 500, PINK);    break;
                case 'g': DrawTexture(TexKey, 797.5, 535, GOLD);    break;
                case 'o':  DrawTexture(TexKey, 832.5, 535, ORANGE); break;
                case 'd':  DrawTexture(TexKey, 867.5, 535, BLUE);   break;
                case 'l':  DrawTexture(TexKey, 797.5, 570, LIME);   break;
                case 'm': DrawTexture(TexKey, 832.5, 570, MAGENTA); break;
                case 'e': DrawTexture(TexKey, 867.5, 570, RED); break;

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
                // Checks the keys so that they appear gray when not collected
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'y') {
                  DrawTexture(TexKey, 797.5, 500, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, YELLOW);
                break;
              }
              case 'v': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'v') {
                  DrawTexture(TexKey, 832.5, 500, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, PURPLE);
                break;
              }
              case 'r': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'r') {
                  DrawTexture(TexKey, 867.5, 500, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, PINK);
                break;
              }
              case 'g': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'g') {
                  DrawTexture(TexKey, 797.5, 535, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, GOLD);
                break;
              }
              case 'o': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'g') {
                  DrawTexture(TexKey, 832.5, 535, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, ORANGE);
                break;
              }
              case 'd': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'd') {
                  DrawTexture(TexKey, 867.5, 535, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, BLUE);
                break;
              }
              case 'l': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'l') {
                  DrawTexture(TexKey, 797.5, 570, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, LIME);
                break;
              }
              case 'm': {
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'm') {
                  DrawTexture(TexKey, 832.5, 570, GRAY);
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
              //
                char f = game.IsKeyVecCheck(x, y);
                if (f == 'e') {
                  DrawTexture(TexKey, 867.5, 570, GRAY);
                }
                DrawTexture(TexKey, xPosition, yPosition, RED);
                break;
              }

              default:     assert(false);  // if this hits you probably forgot to add your new tile type :)
              }
            }
          }
        }
        else
        { 

          // creates end level screen or end game screen so player can decide whether to continue to next level
          // Or can decide to retry in end game after level 3 has been played
          const char* endtxt1 = "Congrats! you have collected all the keys and opened all the gates!";
          const char* endtxt2 = "Press[Y] to continue to next level or [N] to exit game!";
          const char* endtxt3 = "Press[Y] to play again or [N] to exit game!";
      
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