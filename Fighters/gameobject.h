#pragma once

#include "vector2.h"

class GameObject
{
public:
	Vector2 position, size;

	GameObject(Vector2 position, Vector2 size);

	virtual void update(double deltaTime) = 0;
};

