#include "fighterattack.h"
//#include "attacktype.h"
//#include "fighter.h"

FighterAttack::FighterAttack(World& world, Vector2 position, Vector2 size, AttackType attackType, Fighter& fighter) 
	: GameObject{world, position, size, std::make_shared<sf::RectangleShape>(size)}, attackType{attackType}, fighter{&fighter}
{
}

FighterAttack::FighterAttack(World& world, Fighter& fighter)
	: GameObject{world, fighter.position, fighter.size, std::make_shared<sf::RectangleShape>(fighter.size)}, attackType{AttackType::MELEE}, fighter{&fighter}
{
	shape->setFillColor(sf::Color::Transparent);
	shape->setOutlineColor(sf::Color::Red);
	shape->setOutlineThickness(1);

	position.add(fighter.attackDirection.x * (size.x / 2 + fighter.size.x / 2), fighter.attackDirection.y * (size.y / 2 + fighter.size.y / 2));
	shape->setPosition(position);
}

void FighterAttack::update(double deltaTime)
{
	position.add(Vector2::scale(fighter->attackDirection, 100 * deltaTime));
	shape->setPosition(position);
}
