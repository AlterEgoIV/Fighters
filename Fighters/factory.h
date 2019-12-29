#pragma once

#include <memory>
#include "vector2.h"
#include "fighter.h"

class Factory
{
public:
	static std::shared_ptr<Fighter> createPlayerFighter(World& world, Vector2 position, Vector2 size, double speed);
	static std::shared_ptr<Fighter> createAIFighter(World& world, Vector2 position, Vector2 size, double speed, Fighter& target);
};

