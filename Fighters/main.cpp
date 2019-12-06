#include <SFML/Graphics.hpp>
#include "fighter.h"
#include "input.h"
#include "fighterinputdriver.h"
#include "fighteraidriver.h"
#include "factory.h"
#include "renderer.h"
#include <iostream>

void processEvents(sf::RenderWindow& window)
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

std::vector<std::shared_ptr<Fighter>> createFighters()
{
	std::vector<std::shared_ptr<Fighter>> fighters;

	std::shared_ptr<Fighter> playerFighter = Factory::createPlayerFighter(Vector2(0, 0), Vector2(50, 100), 500);
	std::shared_ptr<Fighter> aiFighter = Factory::createAIFighter(Vector2(200, 100), Vector2(50, 100), 100, *playerFighter);
	//aiFighter->driver->isActive = false;

	fighters.push_back(playerFighter);
	fighters.push_back(aiFighter);

	return fighters;
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Fighters");
	window.setKeyRepeatEnabled(false);

	Renderer renderer(window);

	std::vector<sf::Drawable*> drawList;
	std::vector<std::shared_ptr<Fighter>> fighters = createFighters();

	sf::Clock clock;

	while(window.isOpen())
	{
		double deltaTime = clock.restart().asSeconds();

		processEvents(window);

		for(auto& fighter : fighters)
		{
			fighter->update(deltaTime);
			drawList.push_back(&fighter->bodyCollider.shape);
			drawList.push_back(&fighter->attackCollider.shape);
		}

		// Handle attack collisions

		// Handle geometry collisions

		renderer.setDrawList(drawList);
		renderer.render();
		renderer.clearDrawList();
	}

	return 0;
}