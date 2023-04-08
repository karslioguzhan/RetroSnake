/*
    RetroSnake
    Learning C++ while using Raylib
    Source: https://www.youtube.com/watch?v=LGqsnM_WEK4
*/ 

#include <iostream>
#include <raylib.h>
#include "Food.h"
#include "GameSettings.h"


int main()
{
    std::cout << "Staring the Game\n";
    // Get Instance from GameSettings
    GameSettings& gameSettings = GameSettings::getInstance();
    // Starting init window with right parameters
    gameSettings.initGameWindow();
    // Create Food object
    Food food;

    // Run game until game closed
    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Drawing
        ClearBackground(gameSettings.getColor("green"));
        food.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

