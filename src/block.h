#pragma once
#include "definitions.h"
#include <iostream>
#include <math.h>

class Block 
{
    private:
        const float startingXPosition = 0.0f;
        const float startingYPosition = -0.95f;

    public:
        int key = 0;

        int lives = 1;
        float xPosition = 0.0f;
        float yPosition = 0.0f;
        
        float xOffset = 0.035;
        //Block Color
        float r = 0.0f;
        float g = 1.0f;
        float b = 1.0f;
        
        //Block Size
        float xSize = 0.08f;
        float ySize = 0.04f;

        float xHalfSize = 0.0f;
        float yHalfSize = 0.0f;
        float yPositionToCheckUp = 0.0f;
        float yPositionToCheckDown = 0.0f;

        Block();
        Block(float x, float y, int newLives = 1);
        void selectColors();
        bool decreaseLife();
        bool checkCollision(float x, float y);
};