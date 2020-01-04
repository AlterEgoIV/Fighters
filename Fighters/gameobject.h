#pragma once

#include "vector2.h"
#include "objecttype.h"
#include "world.h"
#include "collider.h"

class GameObject
{
public:
	Vector2 position, size, direction;
	std::shared_ptr<sf::Shape> shape;
	double speed;
	ObjectType type;
	Collider collider;

	GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed, ObjectType type);
	GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed = 0);

	virtual void update(double deltaTime) = 0;
	virtual bool collidesWith(GameObject& gameObject){ return false; }
	virtual void resolveCollision(GameObject& gameObject){}

protected:
	World& world;
};

