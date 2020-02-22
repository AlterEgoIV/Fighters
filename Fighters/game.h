#pragma once

#include <SFML/Graphics.hpp>

#include "renderer.h"
#include "world.h"
//#include "gamestate.h"
#include "statename.h"

class GameState;

class Game
{
public:
	Game();
	void run();

	std::map<StateName, std::shared_ptr<GameState>> gameStates;
	std::shared_ptr<GameState> currentState;
	sf::RenderWindow window;
	Renderer renderer;
	sf::Clock clock;

private:
	void processEvents();
};

