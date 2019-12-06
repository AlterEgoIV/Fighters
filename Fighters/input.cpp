#include "input.h"

std::array<bool, sf::Keyboard::KeyCount> Input::keys = {false};

Input::Input()
{
	
}

void Input::keyDown(int keyCode)
{
	keys[keyCode] = true;
}

void Input::keyUp(int keyCode)
{
	keys[keyCode] = false;
}

bool Input::isKeyDown(int keyCode)
{
	return keys[keyCode];
}
