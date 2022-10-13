#include "game.h"

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_Window = SDL_CreateWindow
	(
		"My First Window",		// Title
		250,					// initial x position
		200,					// initial Y position
		640,					// Width in pixels
		480,					// Height in pixels
		0						// Window behaviour flag (ignore for now)
	);

	if (!m_Window)
	{
		printf("[WINDOW] Initialisation failed : % s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;
	}

	//now create the renderer
	m_Renderer = SDL_CreateRenderer
	(
		m_Window,				// Link ther renderer to our newly created window
		-1,						// index rendering driver (ignore for now)
		0						// renderer behaviour flag (ignore for now)
	);

		if (!m_Renderer)
		{
			printf("[RENDERER] Initialisation failed; %s\n", SDL_GetError());
			printf("Press any key to continue\n");
			getchar();
			return;
		}
}

void Game::SetDisplayColour()
{
	if (m_Renderer)
	{
		// Render in our Purple colour
		int result = SDL_SetRenderDrawColor(
			m_Renderer,	// Our Target renderer
			153,		// Red
			0,			// Green
			153,		// Blue
			255			// Alpha
		);

		// Wipe the displau top the colour that we just set
		SDL_RenderClear(m_Renderer);

		// Show what weve drawn
		SDL_RenderPresent(m_Renderer);

		// Pause for 5 secs
		SDL_Delay(1000);
	}
}


Game::~Game()
{
	// Clean Up
	// Dont foreget - we destroy in the REVERSE order they were created

	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}

	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}


		
