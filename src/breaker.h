#pragma once
#include "definitions.h"

class Breaker 
{
    public:
        float xPosition;
        float yPosition;

        float xDirection;
        float yDirection;

        float speed;

        Breaker();
        void movement();
        void changeDirection(int hitDirection);
        void invertYDirection();
};