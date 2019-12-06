#pragma once

#include "driver.h"
#include "fighter.h"

class FighterInputDriver : public Driver
{
public:
	FighterInputDriver(Fighter& fighter);

	void update(double deltaTime) override;

private:
	Fighter& fighter;
};

