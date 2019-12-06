#pragma once

#include <SFML/Graphics.hpp>
#include <array>

class Input
{
public:
	static void keyDown(int keyCode);
	static void keyUp(int keyCode);
	static bool isKeyDown(int keyCode);

private:
	Input();
	static std::array<bool, sf::Keyboard::KeyCount> keys;
};