#pragma once

#include "vector2.h"
#include "objecttype.h"
#include "world.h"

class GameObject
{
public:
	Vector2 position, size;
	std::shared_ptr<sf::Shape> shape;
	double speed;
	ObjectType type;

	GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed = 0, ObjectType type = ObjectType::BLANK);

	virtual void update(double deltaTime) = 0;

protected:
	World& world;
};

