#pragma once
#include <raylib.h>
#include <iostream>
class GameSettings
{
private:
	Color green = { 173, 204, 96, 255 };
	Color darkGreen = { 43, 51, 24, 255 };
	// Grid definition
	int cellSize = 30;
	int cellCount = 25;
	int gameFPS{ 60 };
public:
	Color getColor(std::string colorName) const;
	int getCellSize() const;
	int getCellCount() const;
	void initGameWindow();


};

