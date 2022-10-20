#include "game.h"
#include "input.h"

#undef main

int main(int argc, char* argv[])
{
	Game* game = new Game();			// Create a new game object
	input* input = new input();			// Create an Input object

	if (game && input)
	{
		// Decalre and initialise variables used for colour background
		Uint8 r = 127, g = 127, b = 127, a = 255;

		// Check keys pressed to update variable
		while (!input->KeyIsPressed(KEY_ESCAPE))
		{
			input->Update();

			// Incread r
			if (input->KeyIsPressed(KEY_R))
			{
				if (++r > 255) r = 0;
			}

			// Increase g
			if (input->KeyIsPressed(KEY_G))
			{
				if (++g > 255) g = 0;
			}

			// Increase b
			if (input->KeyIsPressed(KEY_B))
			{
				if (++b > 255) b = 0;
			}

			game->SetDisplayColour(r, g, b, a);				// Set our coloured display
			game->Update();									// Update the game
		}

		delete input;			// Clean Up
		input = nullptr;

		delete game;			// Clean Up
		game = nullptr;

	}

	return 0;			// Exit nicely

}