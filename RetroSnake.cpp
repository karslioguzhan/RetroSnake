/*
    RetroSnake
    Learning C++ while using Raylib
    Source: https://www.youtube.com/watch?v=LGqsnM_WEK4
    Notice: Mostly modified 
*/ 

#include <iostream>
#include <raylib.h>
#include "GameSettings.h"
#include "GameClass.h"



int main()
{
    std::cout << "Staring the Game\n";
    // Get Instance from GameSettings
    GameSettings& gameSettings = GameSettings::getInstance();
    // Starting init window with right parameters
    gameSettings.initGameWindow();

    GameClass game = GameClass();


    // Run game until game closed
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        if (gameSettings.eventTriggered(0.2))
        {
            game.Update();
        }

        game.Move(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_DOWN) || IsKeyReleased(KEY_RIGHT) || IsKeyPressed(KEY_LEFT));

        // Drawing
        ClearBackground(gameSettings.getColor("blue"));
        game.Draw();
        gameSettings.drawBorders();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

