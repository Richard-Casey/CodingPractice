#include "SDL.h"
#include "game.h"

int main(int argc, char* argv[])
{
	Game* game = new Game();				// Create a new game object

		if (game)
		{
			game->SetDisplayColour();	// Set and show our coloured display
			delete game;				// clean up
			game = nullptr;
		}

	return 0;							// Exit nicely
}