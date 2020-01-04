#include "collider.h"

Collider::Collider(Vector2 position, Vector2 size, bool isActive) : shape{size}, isActive{isActive}
{
	shape.setOrigin(shape.getSize().x / 2, shape.getSize().y / 2);
	shape.setPosition(position);
}

bool Collider::collidesWith(Collider& collider)
{
	return shape.getGlobalBounds().intersects(collider.shape.getGlobalBounds());
	/*sf::FloatRect bounds1 = shape.getGlobalBounds();
	sf::FloatRect bounds2 = collider.shape.getGlobalBounds();

	if(bounds1.intersects(bounds2)) return true;

	return false;*/
}

Vector2 Collider::getIntersection(Collider& collider)
{
	sf::FloatRect intersection;
	shape.getGlobalBounds().intersects(collider.shape.getGlobalBounds(), intersection);

	return Vector2(intersection.width, intersection.height);
}

void Collider::set(double positionX, double positionY, double width, double height)
{
	shape.setSize(Vector2(width, height));
	shape.setOrigin(width / 2, height / 2);
	shape.setPosition(positionX, positionY);
}

void Collider::set(Vector2 position, Vector2 size)
{
	shape.setSize(size);
	shape.setOrigin(size.x / 2, size.y / 2);
	shape.setPosition(position);
}

void Collider::transform(double width, double height, double xOffset, double yOffset)
{
	//shape.setSize(Vector2(width, height));
	//shape.setOrigin(width / 2, height / 2);
	//shape.setPosition(position.x + xOffset, position.y + yOffset);
}
