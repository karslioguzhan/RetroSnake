#pragma once
#include <raylib.h>
#include "GameSettings.h"


class Food
{
public:
	Vector2 position;
	Texture2D texture;
	Vector2 generateRandomPosition();
	void Draw();
	Food();
	~Food();
	
};

