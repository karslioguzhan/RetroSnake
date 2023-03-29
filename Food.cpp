#include "Food.h"
GameSettings gameSettings;

Food::Food()
{
	Image image = LoadImage("Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = generateRandomPosition();
}


Vector2 Food::generateRandomPosition()
{
	float x{static_cast<float> (GetRandomValue(0, gameSettings.getCellCount() - 1))};
	float y{static_cast<float> (GetRandomValue(0, gameSettings.getCellCount() - 1))};
	return Vector2{ x, y };
}

void Food::Draw()
{
	DrawTexture(texture, position.x * gameSettings.getCellSize(), position.y * gameSettings.getCellSize(), WHITE);
}

Food::~Food()
{
	UnloadTexture(texture);
}