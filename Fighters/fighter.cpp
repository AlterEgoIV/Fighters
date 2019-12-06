#include "fighter.h"
#include "driver.h"
#include "meleeattack.h"
#include <iostream>

Fighter::Fighter(Vector2 position, Vector2 size, double speed = 0)
	:	GameObject{position, size}, 
		bodyCollider{position, size},
		speed{speed}, 
		attackDirection{Vector2(1, 0)},
		attackCollider{Vector2::add(position, Vector2::multiply(attackDirection, size)), size}
{
	bodyCollider.shape.setFillColor(sf::Color::Transparent);
	bodyCollider.shape.setOutlineColor(sf::Color::Cyan);
	bodyCollider.shape.setOutlineThickness(-8);
	attackCollider.shape.setFillColor(sf::Color::Transparent);
	attackCollider.shape.setOutlineColor(sf::Color::Red);
	attackCollider.shape.setOutlineThickness(-2);

	attacks.emplace(AttackName::MELEE, std::make_shared<MeleeAttack>());
	activeAttacks.push_back(attacks[AttackName::MELEE].get());
}

void Fighter::update(double deltaTime)
{
	driver->update(deltaTime);

	for(auto& attack : activeAttacks)
	{
		attack->update(deltaTime);
	}

	bodyCollider.shape.setPosition(position);
}
