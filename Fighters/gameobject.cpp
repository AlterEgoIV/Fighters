#include "gameobject.h"

GameObject::GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed, ObjectType type)
	: world{world}, position{position}, size{size}, shape{shape}, speed{speed}, type{type}
{
	shape->setOrigin(size.x / 2, size.y / 2);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(position);
}
