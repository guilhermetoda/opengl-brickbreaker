#include "breaker.h"

Breaker::Breaker() 
{
    //Starting position
    xPosition = -1.0f;
    yPosition = randomFloatGenerator(0.2f, 0.4f);
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
    if ((hitDirection == Definitions::right) || (hitDirection == Definitions::left)) 
    {
        xDirection = -xDirection;
    }
    else if ((hitDirection == Definitions::up) || (hitDirection == Definitions::down)) 
    {
        yDirection = -yDirection;
    }
}

float Breaker::randomFloatGenerator(float min, float max) 
{
    return min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
}

void Breaker::invertYDirection() 
{
    yDirection = -yDirection;
}