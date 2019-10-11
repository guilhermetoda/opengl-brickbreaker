#include <glfw3.h>
#include <math.h>
#include "definitions.h"
#include "breaker.h"
#include "renderer.h"
#include "block.h"
#include "player.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector> 

class Game 
{
    public:
        Renderer* renderer;
        Breaker* breaker;
        Player* player;
        std::vector<Block*> blocksMap; 
        int level = 1;
        bool gameState = false;
        void initGame();
        void getInput();

    private:
        bool checkLoseConditions(GLfloat x, GLfloat y);
        void ballMovement();
        void checkBondaries();
        void checkCollisions();
        void checkBlocksCollision();
        void setBlocks();
};


  
   