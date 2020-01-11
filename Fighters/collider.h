#pragma once

#include <SFML/Graphics.hpp>
#include "vector2.h"

class Collider
{
public:
	Collider(Vector2 position, Vector2 size, bool isActive = true, bool isMovable = true, int repulsionForce = 1);
	sf::RectangleShape shape;
	bool isActive, isMovable;
	int repulsionForce;

	bool collidesWith(Collider& collider);
	Vector2 getIntersection(Collider& collider);

	void set(double positionX, double positionY, double width, double height);
	void set(Vector2 position, Vector2 size);
	void transform(double width, double height, double xOffset, double yOffset);
};

