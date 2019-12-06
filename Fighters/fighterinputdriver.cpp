#include "fighterinputdriver.h"
#include "input.h"
#include "vector2.h"
#include <iostream>

FighterInputDriver::FighterInputDriver(Fighter& fighter) : fighter{fighter}
{
}

void FighterInputDriver::update(double deltaTime)
{
	if(isActive)
	{
		if(Input::isKeyDown(sf::Keyboard::Up))
		{
			//fighter.move(0, -fighter.speed * deltaTime);
			fighter.position.add(0, -fighter.speed * deltaTime);
			fighter.attackDirection.set(0, -1);
			fighter.attackCollider.set(fighter.position.x, fighter.position.y - (fighter.size.y / 2 + fighter.size.x / 2), fighter.size.y, fighter.size.x);
			//fighter.updateAttackCollider(fighter.size.y, fighter.size.x, 0, -(fighter.size.y / 2 + fighter.size.x / 2));
			//fighter.attackCollider.shape.setSize(Vector2(fighter.size.y, fighter.size.x));
			//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
			//fighter.attackCollider.shape.setPosition(fighter.position.x, fighter.position.y - fighter.size.y / 2 - fighter.attackCollider.shape.getSize().y / 2);
		}

		if(Input::isKeyDown(sf::Keyboard::Down))
		{
			fighter.position.add(0, fighter.speed * deltaTime);
			fighter.attackDirection.set(0, 1);
			fighter.attackCollider.set(fighter.position.x, fighter.position.y + (fighter.size.y / 2 + fighter.size.x / 2), fighter.size.y, fighter.size.x);
			//fighter.attackCollider.shape.setSize(Vector2(fighter.size.y, fighter.size.x));
			//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
			//fighter.attackCollider.shape.setPosition(fighter.position.x, fighter.position.y + fighter.size.y / 2 + fighter.attackCollider.shape.getSize().y / 2);
		}

		if(Input::isKeyDown(sf::Keyboard::Left))
		{
			fighter.position.add(-fighter.speed * deltaTime, 0);
			fighter.attackDirection.set(-1, 0);
			fighter.attackCollider.set(fighter.position.x - fighter.size.x, fighter.position.y, fighter.size.x, fighter.size.y);
			//fighter.attackCollider.shape.setSize(Vector2(fighter.size.x, fighter.size.y));
			//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
			//fighter.attackCollider.shape.setPosition(fighter.position.x - fighter.size.x / 2 - fighter.attackCollider.shape.getSize().x / 2, fighter.position.y);
		}

		if(Input::isKeyDown(sf::Keyboard::Right))
		{
			fighter.position.add(fighter.speed * deltaTime, 0);
			fighter.attackDirection.set(1, 0);
			fighter.attackCollider.set(fighter.position.x + fighter.size.x, fighter.position.y, fighter.size.x, fighter.size.y);
			//fighter.attackCollider.shape.setSize(Vector2(fighter.size.x, fighter.size.y));
			//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
			//fighter.attackCollider.shape.setPosition(fighter.position.x + fighter.size.x / 2 + fighter.attackCollider.shape.getSize().x / 2, fighter.position.y);
		}

		if(Input::isKeyDown(sf::Keyboard::M))
		{
			
		}
	}
}
