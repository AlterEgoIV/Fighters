#include "fighter.h"
#include "driver.h"
#include "fightermeleeattack.h"
#include <iostream>

Fighter::Fighter(World& world, Vector2 position, Vector2 size, double speed)
	:	GameObject{world, position, size, std::make_shared<sf::RectangleShape>(size)},
		/*bodyCollider{position, size},*/
		speed{speed}, 
		attackDirection{Vector2(1, 0)}
		/*attackCollider{Vector2::add(position, Vector2::multiply(attackDirection, size)), size}*/
{
	/*bodyCollider.shape.setFillColor(sf::Color::Transparent);
	bodyCollider.shape.setOutlineColor(sf::Color::Cyan);
	bodyCollider.shape.setOutlineThickness(-8);
	attackCollider.shape.setFillColor(sf::Color::Transparent);
	attackCollider.shape.setOutlineColor(sf::Color::Red);
	attackCollider.shape.setOutlineThickness(-2);*/

	shape->setFillColor(sf::Color::Transparent);
	shape->setOutlineColor(sf::Color::Cyan);
	shape->setOutlineThickness(-4);

	//attacks.emplace(AttackType::MELEE, std::make_shared<FighterMeleeAttack>());
	//activeAttacks.push_back(attacks[AttackType::MELEE].get());

	currentAttack = AttackType::MELEE;
}

void Fighter::update(double deltaTime)
{
	driver->update(deltaTime);

	//for(auto& attack : activeAttacks)
	//{
	//	//attack->update(deltaTime);
	//}

	//bodyCollider.shape.setPosition(position);
	shape->setPosition(position);
	collider.shape.setPosition(position);

	//std::cout << "Shape position: " << shape->getPosition().x << " " << shape->getPosition().y << "\n";
}

void Fighter::attack()
{
	world.createFighterAttack(*this);
}
