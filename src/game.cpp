#include "game.h"

bool Game::checkLoseConditions(GLfloat x, GLfloat y) 
{
    if (x >= 1.0f || x<= -1.0f || y <= -1.0f || y >= 1.0f) 
    {
        
        return true;
    }
    return false;
}

void Game::initGame() 
{
    renderer = new Renderer();
    breaker = new Breaker();
    player = new Player();
    float xPosition = 0.0f;
    float yPosition = 0.0f;
    double lastTime = glfwGetTime();
    float speed = 0.015f;
    GLfloat xFoward = 0.0f;
    GLfloat yFoward = 0.0f;

    setBlocks();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(renderer->window) && !gameState)
    {
        breaker->movement();
        checkBondaries();
        getInput();
        checkCollisions();
        checkBlocksCollision();
        renderer->render(*breaker, *player, blocksMap);
    }

    glfwTerminate();
}

void Game::getInput() 
{
    if (glfwGetKey( renderer->window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
            if (player->xPosition < 1.0f) 
            {
                player->move(RIGHT);
            }
	    }
	    // Strafe left
	    if (glfwGetKey( renderer->window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		    if (player->xPosition > -1.0f) 
            {
                player->move(LEFT);
            }
	    }
}

void Game::checkCollisions() 
{
    if (player->checkCollision(breaker->xPosition, breaker->yPosition)) 
    {
        breaker->changeDirection(DOWN);
    }
}

void Game::checkBlocksCollision() 
{
    int countIndex = 0;
    for (auto block : blocksMap) 
    {
        if (block->checkCollision(breaker->xPosition, breaker->yPosition)) 
        {
            //std::cout << "BREAKER Y" << breaker->yPosition << "AA ";
            std::cout << "Colliding" << block->xPosition << block->yPosition << "\n";
            //blocksMap.erase(std::remove(blocksMap.begin(), blocksMap.end(), block), blocksMap.end());
            if (block->decreaseLife()) 
            {
                blocksMap.erase(blocksMap.begin() + countIndex);
            }
            else 
            {
                block->selectColors();
            }
            breaker->invertYDirection();
            if (blocksMap.empty()) 
            {
                level++;
                setBlocks();

            }
            
            return;
        }
        countIndex++;
    }
}

void Game::checkBondaries() 
{
    //RIGHT WALL | x >= 1.0f
    //LEFT WALL | x <= -1.0f
    //TOP WALL | y >= 1.0f;
    // BOTTOM WALL | y <= -1.0f

    if (breaker->xPosition >= 1.0f) 
    {
        breaker->changeDirection(RIGHT);
    }
    else if (breaker->xPosition <= -1.0f) 
    {
        breaker->changeDirection(LEFT);
    }
    else if (breaker->yPosition >= 1.0f) 
    {
        breaker->changeDirection(UP);
    }
    else if (breaker->yPosition <= -1.0f)
    {
        // Game over
        breaker = new Breaker();
        //delete breaker;
    }

}

void Game::setBlocks() 
{
    //first line - y = 0.7f
    int numberOfBlocksFirstLine = 8;
    int indexCounter = 0;
    float y = 0.7f;
    float x = -0.8f; 
    float offset = 0.2f;
    
    if (level >0) 
    {
        for (int i = 0; i < numberOfBlocksFirstLine; i++) 
        {
            blocksMap.push_back(new Block(x,y, 1));
            x += offset;
            indexCounter++;
        }
        
    }
    int numberOfBlocksSecondLine = 8;
    y = 0.5f;
    x = -0.8f; 
    offset = 0.2f;
    
    if (level > 1) 
    {
        for (int i = 0; i < numberOfBlocksSecondLine; i++) 
        {
            blocksMap.push_back(new Block(x,y, 2));
            x += offset;
            indexCounter++;
        }

    }
    
    int numberOfBlocksThirdLine = 8;
    y = 0.3f;
    x = -0.8f; 
    offset = 0.2f;
    if (level > 2) 
    {
        for (int i = 0; i < numberOfBlocksThirdLine; i++) 
        {
            blocksMap.push_back(new Block(x,y, 3));
            x += offset;
            indexCounter++;
        }
    }

    if (level >3) 
    {
        breaker->speed = (level+1/2)*0.01f;
    }
    

}