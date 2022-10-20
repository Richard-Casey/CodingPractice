#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <stdio.h>
#include "input.h" // needed for Input* input = new Input();
#include <string>

using namespace std;

struct SDL_Window;
struct SDL_Renderer;
class Bitmap;

class Game
{
public:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
	Game();
	~Game();
	void SetDisplayColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a); // Given arguments in game.cpp
	void Update();
	
	Input* input = new Input();

private:
	SDL_Window* m_window;
	bool m_running;

	Bitmap* m_Monster;
	Bitmap* m_MonsterTrans;
	Bitmap* m_MonsterTransKeyed;

	void CheckEvents();
	void UpdateText();

	Uint8 r = 127, g = 127, b = 127, a = 255; // set eh default values of rgba to 127 for use in Game::Update
};
#endif