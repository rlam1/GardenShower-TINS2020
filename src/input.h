#pragma once

#include <array>

#include <allegro5/allegro.h>

class InputState
{
public:
	InputState();
	~InputState();

	void setKey(int keycode);
	void unsetKey(int keycode);

	bool isKeyActive(int keycode);

private:
	std::array<bool, ALLEGRO_KEY_MAX> keyboard_state;
};

