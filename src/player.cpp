#include "player.h"

Player::Player() 
{
    // Player Color
    r = 1.0f;
    g = 0.0f;
    b = 0.0f;
        
    //Player Size
    xSize = 0.1f;
    ySize = 0.02f;
}

void Player::move(int direction) 
{
    if (direction == Definitions::left) 
    {
        //move Left
        xPosition -= moveSpeed;
    }
    else if (direction == Definitions::right) 
    {
        //move right
        xPosition += moveSpeed;
    }
}
