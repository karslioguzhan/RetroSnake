#pragma once
#include <raylib.h>
#include "GameSettings.h"
#include <deque>
#include "Snake.h"


class Food
{
public:
	Vector2 position;
	Texture2D texture;
	Vector2 generateRandomPosition();
	void Draw();
	bool ElementInDeque(Vector2 foodPosition);
	Vector2 generateRandomCell();
	Food();
	~Food();
	
};

