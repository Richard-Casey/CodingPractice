#pragma once
#include "SDL.h""

//Global vars
enum KEYS_PRESSED_LIST
{
	KEY_ESCAPE, KEY_R, KEY_G, KEY_B, SIZE_OF_KEYS_PRESSED_ENUM
};

class Input
{
public:
	void Update(void);
	bool KeyIsPressed(KEYS_PRESSED_LIST key);
	Input();
	~Input();
	SDL_Event m_Event;
	bool m_KeysPressed[SIZE_OF_KEYS_PRESSED_ENUM];
};

