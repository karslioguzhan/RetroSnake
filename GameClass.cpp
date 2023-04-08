#include "GameClass.h"

void GameClass::Draw()
{
	food.Draw();
	snake.Draw();
}

void GameClass::Update()
{
	snake.Update();
}

void GameClass::Move(bool keyPressed)
{
	if (IsKeyPressed(KEY_UP) && snake.direction.y !=  1)
	{
		snake.direction = { 0, -1 };
	}
	if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
	{
		snake.direction = { 0, 1 };
	}
	if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
	{
		snake.direction = { -1, 0 };
	}
	if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
	{
		snake.direction = { 1, 0 };
	}
}
