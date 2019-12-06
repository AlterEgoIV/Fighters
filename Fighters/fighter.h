#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "collider.h"
#include "attackname.h"

class Driver;
class Attack;

class Fighter : public GameObject
{
public:
	Vector2 attackDirection;
	Collider bodyCollider, attackCollider;
	double speed;
	std::map<AttackName, std::shared_ptr<Attack>> attacks;
	std::vector<Attack*> activeAttacks;
	std::unique_ptr<Driver> driver;

	Fighter(Vector2 position, Vector2 size, double speed);

	void update(double deltaTime) override;
};

