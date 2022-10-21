#define GLEW_STATIC // Tells GLEW that we are going to include its code straight into the exe (statically)

#include <glew.h>					// Need to be first
#include <SDL_opengl.h>			
#include <glm/glm.hpp>				// GLM is the maths library
#include <glm/gtc/type_ptr.hpp>
#include <SDL.h>					// SDL is our window library
#include <iostream>					// iostream for cout	

using namespace std;

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);	// We initialise SDL so that we can use any feature in SDL that we want
									// Without having to enable it later down the line

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);		// First 4 set up depth pf RGBA
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);		
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);		// Alpha is the level of transparancy
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);	// Tells openGL how many bits per pixel so it can set up the buffer properly
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);	// Enables Double Buffering
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);	// Tells openGL that we dont want old depreceated functionality
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);		// Sets up our depth buffer bit size (needed for shadow mapping)

	SDL_Window* window = SDL_CreateWindow("My Window!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
											800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

	SDL_GLContext GLContext = SDL_GL_CreateContext(window);		// Creates a window and an openGL context

	glewExperimental = GL_TRUE;			// Enable Glew
	GLenum status = glewInit();

	glEnable(GL_DEPTH_TEST);			// Enable Depth testing
	glDepthFunc(GL_LESS);

	if (status != GLEW_OK)				// Being safe and checking that GLEW initialised correctly
	{
		cout << "GLEW failed to initialise!" << endl;
	}

	while (true)	// Creat an infinate loop, clear the screen and present the result
	{
		glClearColor(0.0f, 0.15f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glViewport(0, 0, 800, 600);

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(GLContext);		// Clean up
	SDL_DestroyWindow(window);				// Clean up
	window = NULL;							// Clean up
	SDL_Quit();								// Clean up

	return 0;
}