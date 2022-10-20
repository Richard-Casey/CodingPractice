#include "game.h"
#include "input.h"


void Game::SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	if (m_Renderer)
	{
		// Render in our Purple colour
		int result = SDL_SetRenderDrawColor(
			m_Renderer,	// Our Target renderer
			r,			// Red
			g,			// Green
			b,			// Blue
			a			// Alpha
		);

		// Wipe the display top the colour that we just set
		//SDL_RenderClear(m_Renderer);

		// Show what weve drawn
		//SDL_RenderPresent(m_Renderer);

		// Pause for 5 secs
		//SDL_Delay(1000);
	}
}

void Game::CheckEvents()
{

}

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start up
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_Window = SDL_CreateWindow
	(
		"We're getting there - Here have a window, congratulations",		// Title
		600,					// initial x position
		300,					// initial Y position
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

Game::~Game()
{
	delete input;
	input = nullptr;
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

void Game::Update(void)
{
	input->Update();

	// Increase r value
	if (input->KeyIsPressed(KEY_R))
	{
		if (++r > 255) r = 0; // if the value of r reaches 255 it resets to 0
	}

	// Increase g value
	if (input->KeyIsPressed(KEY_G))
	{
		if (++g > 255) g = 0; // if the value of g reaches 255 it resets to 0
	}

	// Increase b value
	if (input->KeyIsPressed(KEY_B))
	{
		if (++b > 255) b = 0; // if the value of b reaches 255 it resets to 0
	}

	SetDisplayColour(r, g, b, a); // Set our colour display (rgba defined in the game header)

	SDL_RenderPresent(m_Renderer);	// Show what we've drawn

	SDL_Delay(16);	// Pause for 1/60th sec (ish)
	
}