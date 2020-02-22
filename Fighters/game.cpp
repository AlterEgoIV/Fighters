#include "game.h"
#include "input.h"

#include <iostream>
#include "gamestate.h"
#include "playgamestate.h"
#include "mainmenugamestate.h"

Game::Game() : window(sf::VideoMode(800, 600), "Fighters"), renderer(window)
{
	window.setKeyRepeatEnabled(false);

	gameStates.emplace(StateName::MAINMENU_STATE, std::make_shared<MainMenuGameState>(*this));
	gameStates.emplace(StateName::PLAY_STATE, std::make_shared<PlayGameState>(*this));

	currentState = gameStates[StateName::PLAY_STATE];
}

void Game::run()
{
	while(window.isOpen())
	{
		double deltaTime = clock.restart().asSeconds();

		processEvents();

		currentState->update(deltaTime);

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
