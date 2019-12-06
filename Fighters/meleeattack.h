#pragma once

#include "attack.h"

class MeleeAttack : public Attack
{
public:
	MeleeAttack();

	void update(double deltaTime) override;
};

