#include "gameobject.h"

GameObject::GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed, ObjectType type)
	: world{world}, position{position}, size{size}, direction{Vector2(1, 0)}, shape{shape}, speed{speed}, type{type}, collider{position, size}
{
	shape->setOrigin(size.x / 2, size.y / 2);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(position);
}

GameObject::GameObject(World& world, Vector2 position, Vector2 size, std::shared_ptr<sf::Shape> shape, double speed)
	: world{world}, position{position}, size{size}, direction{Vector2(1, 0)}, shape{shape}, speed{speed}, type{ObjectType::BLANK}, collider{position, size}
{
	shape->setOrigin(size.x / 2, size.y / 2);
	shape->setFillColor(sf::Color::White);
	shape->setPosition(position);
}
