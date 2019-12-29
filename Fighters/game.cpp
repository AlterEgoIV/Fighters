#include "game.h"
#include "input.h"

#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Fighters"), renderer(window), world(renderer)
{
	window.setKeyRepeatEnabled(false);
}

void Game::run()
{
	while(window.isOpen())
	{
		double deltaTime = clock.restart().asSeconds();

		processEvents();

		world.update(deltaTime);

		renderer.render();
		renderer.clearDrawList();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
			{
				window.close();
				break;
			}

			case sf::Event::KeyPressed:
			{
				Input::keyDown(event.key.code);
				std::cout << "Key " << event.key.code << " pressed\n";

				break;
			}

			case sf::Event::KeyReleased:
			{
				Input::keyUp(event.key.code);
				std::cout << "Key " << event.key.code << " released\n";
				break;
			}
		}
	}
}
