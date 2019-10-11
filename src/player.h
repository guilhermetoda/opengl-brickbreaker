#pragma once
#include "block.h"

class Player : public Block 
{
    private:
        float moveSpeed = 0.02f;
    public:
        Player();
        void move(int direction);
};