#include "renderer.h"
#include <iostream>

Renderer::Renderer(sf::RenderWindow& window) : window{window}
{
}

void Renderer::appendToDrawList(sf::Drawable& drawable)
{
	drawList.push_back(&drawable);
}

void Renderer::appendToDrawList(std::vector<sf::Drawable*>& drawables)
{
	this->drawList.insert(this->drawList.end(), drawList.begin(), drawList.end());
}

void Renderer::setDrawList(std::vector<sf::Drawable*>& drawList)
{
	this->drawList = drawList;
}

void Renderer::clearDrawList()
{
	drawList.clear();
}

void Renderer::render()
{
	//std::cout << drawList.size() << std::endl;
	window.clear();
	for(auto& drawable : drawList)
	{
		window.draw(*drawable);
	}
	window.display();
}
