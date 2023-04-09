#pragma once
#include "Food.h"
#include "Snake.h"

class GameClass
{
public:
    GameClass();
    ~GameClass();
    // Create Food object
    Food food;
    bool gameRunning{ true };
    int score{ 0 };
    // Create Snake object
    Snake& snake = Snake::GetInstance();
    void Draw();
    void DrawInfo();
    void Update();
    void Move(bool keyPressed);
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);
    void GameOver();
    // Sound
    Sound eatSound;
    Sound wallSound;
};

