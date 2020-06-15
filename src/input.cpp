#include "include/input.h"

InputState::InputState()
{
	keyboard_state.fill(false);
}

InputState::~InputState()
{
}

void InputState::setKey(int keycode)
{
	keyboard_state.at(keycode) = true;
}

void InputState::unsetKey(int keycode)
{
	keyboard_state.at(keycode) = false;
}

const bool InputState::isKeyActive(int keycode) const
{
	return keyboard_state.at(keycode);
}
