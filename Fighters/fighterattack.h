#pragma once

#include "gameobject.h"
#include "attacktype.h"
#include "fighter.h"

//class Fighter;

class FighterAttack : public GameObject
{
public:
	AttackType attackType;
	Fighter* fighter;
	FighterAttack(World& world, Vector2 position, Vector2 size, AttackType attackType, Fighter& fighter);
	FighterAttack(World& world, Fighter& fighter);
	void update(double deltaTime) override;
};

