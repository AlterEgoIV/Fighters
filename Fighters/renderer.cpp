#include "renderer.h"

Renderer::Renderer(sf::RenderWindow& window) : window{window}
{
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
	window.clear();
	for(auto& drawable : drawList)
	{
		window.draw(*drawable);
	}
	window.display();
}
