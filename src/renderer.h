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
        
        void renderBreaker(const Breaker& breaker);
        void checkBreakerPlayerCollision(const Breaker& breaker);
        void render(const Breaker& breaker, const Block& player, const std::vector<Block*>& blocksMap);
        void renderPlayer(const Block& player);
        void renderBlocks(const std::vector<Block*>& blocksMap);
        void getInput();
       

    private:
        float movingIndex = 0.0f;
        float xPosition = 0.0f;
        GLfloat xSize = 0.0f;
        GLfloat ySize = 0.0f;
        const GLfloat startingSquareSize = 0.02f;
};