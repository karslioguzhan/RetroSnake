#include "GameSettings.h"

Color GameSettings::getColor(std::string colorName) const
{
    if (colorName == "green")
    {
        return green;
    }
    return darkGreen;
}

int GameSettings::getCellSize() const
{
    return cellSize;
}

int GameSettings::getCellCount() const
{
    return cellCount;
}

void GameSettings::initGameWindow()
{
    InitWindow(cellSize * cellCount, cellSize * cellCount, "Retro Snake");
    SetTargetFPS(gameFPS);
}


