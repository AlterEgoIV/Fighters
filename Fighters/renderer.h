#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Renderer
{
public:
	Renderer(sf::RenderWindow& window);
	void setDrawList(std::vector<sf::Drawable*>& drawList);
	void clearDrawList();
	void render();

private:
	sf::RenderWindow& window;
	std::vector<sf::Drawable*> drawList;
};

