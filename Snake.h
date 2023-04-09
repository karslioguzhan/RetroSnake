#pragma once
#include <deque>
#include <raylib.h>
#include "GameSettings.h"
#include <raymath.h>


class Snake
{
public:
	static Snake& GetInstance();
	std::deque<Vector2> body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	void Draw();
	void Update();
	Vector2 direction{ 1, 0 };
	bool addSegment{ false };
	void Reset();
private:
	Snake() {};

};

