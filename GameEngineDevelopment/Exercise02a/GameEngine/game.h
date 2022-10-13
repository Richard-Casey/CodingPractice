#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>

class Game
{
public:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	Game();
	~Game();
	void SetDisplayColour(void);
};
#endif