#pragma once

#include "vector2.h"
#include "driver.h"

class Fighter;

class FighterAIDriver : public Driver
{
public:
	FighterAIDriver(Fighter& fighter, Fighter& target);

	void update(double deltaTime) override;

private:
	Fighter& fighter;
	Fighter& target;
	Vector2 direction;
};

