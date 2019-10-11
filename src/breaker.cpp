#include "breaker.h"

Breaker::Breaker() 
{
    //Starting position
    xPosition = -1.0f;
    yPosition = 0.2f;
    //Breaker Speed
    speed = 0.01f;
    xDirection = speed;
    yDirection = -speed;
}

void Breaker::movement() 
{
    xPosition += xDirection;
    yPosition += yDirection;
}

void Breaker::changeDirection(int hitDirection) 
{
    if ((hitDirection == RIGHT) || (hitDirection == LEFT)) 
    {
        xDirection = -xDirection;
    }
    else if ((hitDirection == UP) || (hitDirection == DOWN)) 
    {
        yDirection = -yDirection;
    }
}

void Breaker::invertYDirection() 
{
    yDirection = -yDirection;
}