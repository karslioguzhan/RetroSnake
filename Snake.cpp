#include "Snake.h"

Snake& Snake::GetInstance()
{
	static Snake instance;
	return instance;
}

void Snake::Draw()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	for (auto numBody : body)
	{
		Rectangle segment = Rectangle{gameSettings.getOffset() + numBody.x * gameSettings.getCellSize(),
			gameSettings.getOffset() + numBody.y * gameSettings.getCellSize(), static_cast<float> (gameSettings.getCellSize()),
			static_cast<float> (gameSettings.getCellSize())};
		DrawRectangleRounded(segment, 0.8, 6, gameSettings.getColor("darkblue"));
	}
}

void Snake::Update()
{
	body.push_front(Vector2Add(body[0], direction));
	if (addSegment == true)
	{
		addSegment = false;
	}
	else
	{
		body.pop_back();
	}
}

void Snake::Reset()
{
	body = { Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9} };
	direction = { 1, 0 };
}
