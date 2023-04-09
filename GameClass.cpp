#include "GameClass.h"

GameClass::GameClass()
{
	InitAudioDevice();
	eatSound = LoadSound("Sounds/eat.mp3");
	wallSound = LoadSound("Sounds/wall.mp3");
}

GameClass::~GameClass()
{
	UnloadSound(eatSound);
	UnloadSound(wallSound);
	CloseAudioDevice();
}

void GameClass::Draw()
{
	food.Draw();
	snake.Draw();
	DrawInfo();
}

void GameClass::DrawInfo()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	DrawText("Retro Snake", gameSettings.getOffset() - 5, 20, 40, gameSettings.getColor("darkblue"));
	DrawText(TextFormat("Highscore: %i", score), gameSettings.getOffset() - 5, 
		gameSettings.getOffset() + gameSettings.getCellSize() * gameSettings.getCellCount() +10,
		40, gameSettings.getColor("darkblue"));
}

void GameClass::Update()
{
	if (gameRunning)
	{
		snake.Update();
		CheckCollisionWithFood();
		CheckCollisionWithEdges();
		CheckCollisionWithTail();
	}
}

void GameClass::Move(bool keyPressed)
{
	if (IsKeyPressed(KEY_UP) && snake.direction.y !=  1)
	{
		snake.direction = { 0, -1 };
		gameRunning = true;
		
	}
	if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1)
	{
		snake.direction = { 0, 1 };
		gameRunning = true;
	}
	if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1)
	{
		snake.direction = { -1, 0 };
		gameRunning = true;
	}
	if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1)
	{
		snake.direction = { 1, 0 };
		gameRunning = true;
	}
}

void GameClass::CheckCollisionWithFood()
{
	if (Vector2Equals(snake.body[0], food.position))
	{
		food.position = food.generateRandomPosition();
		snake.addSegment = true;
		++score;
		PlaySound(eatSound);
	}
}

void GameClass::CheckCollisionWithEdges()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	bool outsideX{ snake.body[0].x == gameSettings.getCellCount() || snake.body[0].x == -1 };
	bool outsideY{ snake.body[0].y == gameSettings.getCellCount() || snake.body[0].y == -1 };
	if (outsideX || outsideY)
	{
		GameOver();
	}
}

void GameClass::CheckCollisionWithTail()
{
	
	std::deque<Vector2> headlessBody{ snake.body };
	headlessBody.pop_front();
	if (ElementInDeque(snake.body[0], headlessBody))
	{
		GameOver();
	}

}

bool GameClass::ElementInDeque(Vector2 element, std::deque<Vector2> deque)
{
	for (auto numElement: deque)
	{
		if (Vector2Equals(numElement, element))
		{
			return true;
		}
	}
	return false;
}

void GameClass::GameOver()
{
	GameSettings& gameSettings = GameSettings::getInstance();
	int middlePos{(gameSettings.getOffset()+ gameSettings.getCellSize()* gameSettings.getCellCount())/2};
	PlaySound(wallSound);
	WaitTime(5);
	snake.Reset();
	food.position = food.generateRandomPosition();
	gameRunning = false;
	score = 0;
}
