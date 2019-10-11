#include <glfw3.h>
#include <stdio.h>     /* srand, rand */
#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "block.h"
#include "breaker.h"

class Renderer
{
    public:

        GLFWwindow* window;
        Renderer();
        void renderQuad(GLfloat x, GLfloat y, GLfloat R = 0.0f, GLfloat G = 0.0f, GLfloat B = 0.0f);
        void renderObjectWithSize(GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat xSize, GLfloat ySize);
        
        void renderBreaker(Breaker *breaker);
        void checkBreakerPlayerCollision(Breaker* breaker);
        void render(Breaker *breaker, Block* player, std::vector<Block*> blocksMap);
        void renderPlayer(Block *player);
        void renderBlocks(std::vector<Block*> blocksMap);
        void getInput();
       

    private:
        float movingIndex = 0.0f;
        float xPosition = 0.0f;
        GLfloat xSize = 0.0f;
        GLfloat ySize = 0.0f;
        const GLfloat startingSquareSize = 0.02f;
};