#pragma once

#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "world.h"

class Game
{
public:
	Game();
	void run();

	sf::RenderWindow window;
	Renderer renderer;
	sf::Clock clock;
	World world;

private:
	void processEvents();
};

