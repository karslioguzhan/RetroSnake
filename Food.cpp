#include "Food.h"


Food::Food()
{
	Image image = LoadImage("Graphics/food.png");
	texture = LoadTextureFromImage(image);
	UnloadImage(image);
	position = generateRandomPosition();
}

Vector2 Food::generateRandomCell()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	float x{ static_cast<float> (GetRandomValue(0, gameSettings.getCellCount() - 1)) };
	float y{ static_cast<float> (GetRandomValue(0, gameSettings.getCellCount() - 1)) };
	return Vector2 { x,y };
}


Vector2 Food::generateRandomPosition()
{
	Vector2 position{ generateRandomCell() };
	
	while (Food::ElementInDeque(position))
	{
		position = generateRandomCell();
		
	} 

	return position;
}

void Food::Draw()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	DrawTexture(texture, gameSettings.getOffset() + position.x * gameSettings.getCellSize(), gameSettings.getOffset() + position.y * gameSettings.getCellSize(), WHITE);
}

Food::~Food()
{
	UnloadTexture(texture);
}

bool Food::ElementInDeque(Vector2 foodPosition)
{
	GameSettings& gameSettings = GameSettings::getInstance();
	Snake& snake = Snake::GetInstance();
	std::deque<Vector2> snakeBody{ snake.body };
	for (auto partSnakeBody : snakeBody)
	{
		if (Vector2Equals(partSnakeBody, foodPosition))
		{
			return true;
		}
	}
	return false;
}
