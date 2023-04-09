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
		Rectangle segment = Rectangle{numBody.x * gameSettings.getCellSize(),
			numBody.y * gameSettings.getCellSize(), static_cast<float> (gameSettings.getCellSize()),
			static_cast<float> (gameSettings.getCellSize())};
		DrawRectangleRounded(segment, 0.8, 6, gameSettings.getColor("darkgreen"));
	}
}

void Snake::Update()
{
	body.pop_back();
	body.push_front(Vector2Add(body[0], direction));
}
