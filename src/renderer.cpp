#include "renderer.h"

//initializing window object
Renderer::Renderer() : window() {
    srand(time(NULL));
    xSize = startingSquareSize;
    ySize = startingSquareSize;

    /* Initialize the library */
    if (!glfwInit()) 
    {
        std::cout << "Failed to Initialize GLFW\n";
    }
        

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "Brick Breaker", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Window Closed\n";
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

	glfwSwapInterval( 1 );

	// set up view
	//glViewport( 0, 0, 400, 400 );
    glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
}


void Renderer::renderQuad(GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B) {
    //float colorRand = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    
    glPushMatrix();
	glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        glColor3f(R,G,B);                      // Draw A Quad
        glVertex3f( -xSize, ySize, 0.0f);              // Top Left
        glVertex3f( xSize, ySize, 0.0f);              // Top Right
        glVertex3f( xSize,-ySize, 0.0f);              // Bottom Right
        glVertex3f(-xSize,-ySize, 0.0f);              // Bottom Left
    glEnd();
    glFlush();				/* Complete any pending operations */
    glPopMatrix();
}   

void Renderer::renderObjectWithSize(GLfloat x, GLfloat y, GLfloat R, GLfloat G, GLfloat B, GLfloat xSize, GLfloat ySize) {
    
    glPushMatrix();
	glTranslatef(x, y, 0.0);
    glBegin(GL_QUADS);
        glColor3f(R,G,B);                      // Draw A Quad
        glVertex3f( -xSize, ySize, 0.0f);              // Top Left
        glVertex3f( xSize, ySize, 0.0f);              // Top Right
        glVertex3f( xSize,-ySize, 0.0f);              // Bottom Right
        glVertex3f(-xSize,-ySize, 0.0f);              // Bottom Left
    glEnd();
    glFlush();				/* Complete any pending operations */
    glPopMatrix();
}  

void Renderer::renderPlayer(const Block& player) 
{
    renderObjectWithSize(player.xPosition, player.yPosition, player.r, player.g, player.b, player.xSize, player.ySize);
}

void Renderer::renderBreaker(const Breaker& breaker) 
{
    renderQuad(breaker.xPosition, breaker.yPosition, 1.0f,1.0f,1.0f);
}

void Renderer::renderBlocks(const std::vector<Block*>& blocksMap) 
{
    for (auto block : blocksMap) 
    {
        renderObjectWithSize(block->xPosition, block->yPosition, block->r, block->g, block->b, block->xSize, block->ySize);
    }
        
}

void Renderer::render(const Breaker& breaker, const Block& player, const std::vector<Block*>& blocksMap) 
{
    // glfwGetTime is called only once, the first time this function is called
	    // Compute time difference between current and last frame
	    double currentTime = glfwGetTime();
	    //float deltaTime = float(currentTime - lastTime);
        //printf ("Delta Time %f\n", deltaTime);
        /* Render here */
        //glClear(GL_COLOR_BUFFER_BIT);
        glClearColor ( 0.1f, 0.1f, 0.1f, 1.0f );
	    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderBreaker(breaker);
        renderPlayer(player);
        renderBlocks(blocksMap);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
}

