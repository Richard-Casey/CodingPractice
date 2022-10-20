#include "SDL.h"
#include "game.h"
#include "input.h"
#undef main

int main(int argc, char* argv[])
{
	Game* game = new Game();				// Create a new game object

		if (game)
		{
			while (!game->input->KeyIsPressed(KEY_ESCAPE)) // While the escape key is NOT being pressed - Update the game!
															// This is the main loop for the whole progamme
			{
				game->Update();
			}

			delete game;				// clean up
			game = nullptr;
		}

	return 0;							// Exit nicely
}