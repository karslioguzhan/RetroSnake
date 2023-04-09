#pragma once
#include "Food.h"
#include "Snake.h"

class GameClass
{
public:
    // Create Food object
    Food food;
    // Create Snake object
    Snake& snake = Snake::GetInstance();
    void Draw();
    void Update();
    void Move(bool keyPressed);
    void CheckCollisionWithFood();
};

