#pragma once
#include <stdlib.h>     /* srand, rand */
#include "definitions.h"

class Breaker 
{
    public:
        float xPosition = 0.0f;
        float yPosition = 0.0f;

        float xDirection = 0.0f;
        float yDirection = 0.0f;

        float speed = 0.0f;

        Breaker();
        void movement();
        void changeDirection(int hitDirection);
        void invertYDirection();
        float randomFloatGenerator(float min, float max);
};