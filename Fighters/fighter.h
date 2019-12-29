#pragma once

#include <SFML/Graphics.hpp>
#include "gameobject.h"
#include "collider.h"
#include "attacktype.h"

class Driver;
class FighterAttack;

class Fighter : public GameObject
{
public:
	Vector2 attackDirection;
	Collider bodyCollider, attackCollider;
	double speed;
	std::map<AttackType, std::shared_ptr<FighterAttack>> attacks;
	std::vector<FighterAttack*> activeAttacks;
	std::unique_ptr<Driver> driver;
	AttackType currentAttack;

	Fighter(World& world, Vector2 position, Vector2 size, double speed = 0);

	void update(double deltaTime) override;
	void attack();
};

