#include <glfw3.h>
#include <math.h>
#include "definitions.h"
#include "game.h"     
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Game* game;
bool gameState = false;

int main(void)
{  
    game = new Game();
    float xPosition = 0.0f;
    float yPosition = 0.0f;
    double lastTime = glfwGetTime();
    float speed = 0.015f;
    GLfloat xFoward = 0.0f;
    GLfloat yFoward = 0.0f;

    game->initGame();

    return 0;
}