#include "SDL.H"
#include "input.h"

input::input()
{

}

void input::Update(void)
{
	// Loop throuigh all of the events in the event list
	while (SDL_PollEvent(&m_Event) != NULL)
	{
		// We got an event! Lets do something with it - or process it

		// Check for keydown
		if (m_Event.type == SDL_KEYDOWN)
		{
			// Cache the code of the key we pressed for easier debuggin
			SDL_Keycode keyPressed = m_Event.key.keysym.sym;

			// Update keys
			switch (keyPressed)
			{
			case SDLK_ESCAPE:
				m_KeysPressed[KEY_ESCAPE] = true;
				break;

			case SDLK_r:
				m_KeysPressed[KEY_R] = true;
				break;

			case SDLK_g:
				m_KeysPressed[KEY_G] = true;
				break;

			case SDLK_b:
				m_KeysPressed[KEY_B] = true;
				break;

			}
		}

		// Check for the key up
		else if (m_Event.type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = m_Event.key.keysym.sym;

			// Update Keys
			switch (keyPressed)
			{
			case SDLK_r:
				m_KeysPressed[KEY_R] = false;
				break;

			case SDLK_g:
				m_KeysPressed[KEY_G] = false;
				break;

			case SDLK_b:
				m_KeysPressed[KEY_B] = false;
				break;
			}
		}
	}
}

input::~input()
{

}

bool input::KeyIsPressed(KEYS_PRESSED_LIST key)
{
	return m_KeysPressed[key];
}