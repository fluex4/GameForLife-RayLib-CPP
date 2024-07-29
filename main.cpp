#include <iostream>
#include <raylib.h>
#include"simulation.hpp"

using namespace std;


const int WINDOW_WIDTH=750,WINDOW_HEIGHT=750;
const int cellSize=10;
int FPS=12;

int main () {
    
    InitWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"Game of Life");
    SetTargetFPS(FPS);
    Simulation sim{WINDOW_WIDTH,WINDOW_HEIGHT,cellSize};

    //Simulation Loop
    // 1. Event 2. Update  3. Draw
    while(!WindowShouldClose()){
        //1. Event handling
        if(IsKeyPressed(KEY_P)){
            Vector2 mouse = GetMousePosition();
            int x=mouse.x/cellSize;
            int y=mouse.y/cellSize;

            sim.Toggle(y,x);
            printf("%d,%d",x,y);
        }
        if(IsKeyReleased(KEY_R)){
            sim.FillRandom();
        }
        if(IsKeyReleased(KEY_C)){
            sim.Clear();
        }
        if(IsKeyReleased(KEY_ENTER)){
            sim.Start();
            SetWindowTitle("Game of Title is Running ...");
        }
        
        if(IsKeyReleased(KEY_SPACE)){
            sim.Stop();
            SetWindowTitle("Game of Title has Stopped Running !!!");
        }
        if(IsKeyReleased(KEY_KP_ADD)){
            SetTargetFPS(GetFPS()+5);
        }
        if(IsKeyReleased(KEY_KP_SUBTRACT)){
            if(GetFPS()>30)
                SetTargetFPS(GetFPS()-5);
        }

        //2. Updating
        sim.Update();


        //3. Drawing
        BeginDrawing();
        sim.Draw();
        ClearBackground(BLACK);
        EndDrawing();
    }



    CloseWindow();
    return 0;
}