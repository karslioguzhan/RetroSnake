#include "GameSettings.h"



GameSettings::GameSettings()
{
    std::cout << "GameSettings created\n";
}

GameSettings& GameSettings::getInstance()
{
    static GameSettings instance;
    return instance;
}

Color GameSettings::getColor(std::string colorName) const
{
    if (colorName == "blue")
    {
        return blue;
    }
    return darkBlue;
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
    InitWindow(2*offset+cellSize * cellCount, 2 * offset+cellSize * cellCount, "Retro Snake");
    SetTargetFPS(gameFPS);
}

bool GameSettings::eventTriggered(double interval)
{
    double currentTime{ GetTime() };
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

void GameSettings::drawBorders()
{
    Rectangle borders{ static_cast<float>(offset) - 5, static_cast<float>(offset) - 5, cellSize * cellCount + 10, cellSize * cellCount + 10 };
    DrawRectangleLinesEx(borders, 5, darkBlue);
}

int GameSettings::getOffset()
{
    return offset;
}


