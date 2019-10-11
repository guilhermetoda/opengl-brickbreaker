#include "block.h"

Block::Block() 
{
    xPosition = startingXPosition;
    yPosition = startingYPosition;
    xHalfSize = abs(xSize / 2) + xOffset;
    yHalfSize = abs(ySize / 2);
    yPositionToCheckUp = yPosition + yHalfSize;
    yPositionToCheckDown = yPosition - yHalfSize;
    key = -1;
}

Block::Block(float x, float y, int newLives) 
{
    xPosition = x;
    yPosition = y;
    lives = newLives;
    xHalfSize = abs(xSize / 2) + xOffset;
    yHalfSize = abs(ySize / 2);
    yPositionToCheckUp = yPosition + yHalfSize;
    yPositionToCheckDown = yPosition - yHalfSize;
    selectColors();
}

void Block::selectColors() 
{
    if (lives == 3) 
    {
        r = 1.0f;
        g = 0.0f;
        b = 0.0f;
    }
    else if (lives == 2) 
    {
        r = 1.0f;
        g = 1.0f;
        b = 0.0f;
    }
    else if (lives == 1) 
    {
        r = 0.0f;
        g = 1.0f;
        b = 0.0f;
    }
}

bool Block::decreaseLife() 
{
    lives--;
    if (lives == 0) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}

bool Block::checkCollision(float x, float y)
{
    if (y <= yPositionToCheckUp && y >= yPositionToCheckDown) 
    {
        float leftEnd = xPosition - xHalfSize;
        float rightEnd = xPosition + xHalfSize;
        std::cout << "left" << leftEnd << "\n";
        std::cout << "right" << rightEnd << "\n";
        if (x >= leftEnd && x <= rightEnd) 
        {
            return true;
        }
    }
    return false;
}
