#pragma once
#include <raylib.h>
#include <iostream>
// As Singleton
class GameSettings
{
private:
	Color blue{SKYBLUE};
	Color darkBlue{DARKBLUE};
	// Grid definition
	int cellSize{ 30 };
	int cellCount{ 25 };
	int offset{ 75 };
	int gameFPS{ 60 };
	// Time handling
	double lastUpdateTime{ 0 };
public:
	static GameSettings& getInstance();
	Color getColor(std::string colorName) const;
	int getCellSize() const;
	int getCellCount() const;
	void initGameWindow();
	bool eventTriggered(double interval);
	void drawBorders();
	int getOffset();
private:
	GameSettings();


};

