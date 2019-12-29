#include "world.h"
#include "factory.h"
#include "attacktype.h"
#include "fighter.h"
#include "fighterattack.h"
//#include "fightermeleeattack.h"
#include <iostream>

World::World(Renderer& renderer) : renderer{renderer}
{
	createGameObjects();
}

void World::update(double deltaTime)
{
	for(auto& gameObject : gameObjects)
	{
		gameObject->update(deltaTime);
		renderer.appendToDrawList(*gameObject->shape);
	}

	gameObjects.insert(gameObjects.end(), gameObjectsToAdd.begin(), gameObjectsToAdd.end());
	gameObjectsToAdd.clear();
}

void World::createGameObjects()
{
	std::vector<std::shared_ptr<Fighter>> fighters = createFighters();

	gameObjects.insert(gameObjects.end(), fighters.begin(), fighters.end());
}

std::vector<std::shared_ptr<Fighter>> World::createFighters()
{
	std::vector<std::shared_ptr<Fighter>> fighters;

	std::shared_ptr<Fighter> playerFighter = Factory::createPlayerFighter(*this, Vector2(0, 0), Vector2(50, 100), 500);
	std::shared_ptr<Fighter> aiFighter = Factory::createAIFighter(*this, Vector2(200, 100), Vector2(50, 100), 100, *playerFighter);
	//aiFighter->driver->isActive = false;

	fighters.push_back(playerFighter);
	fighters.push_back(aiFighter);

	return fighters;
}

void World::createFighterAttack(Fighter& fighter)
{
	//std::shared_ptr<GameObject> attack = std::make_shared<FighterAttack>(*this, fighter);

	//gameObjects.push_back(attack);
	gameObjectsToAdd.push_back(std::make_shared<FighterAttack>(*this, fighter));

	//std::shared_ptr<FighterAttack> fighterAttack;

	//switch(fighter.currentAttack)
	//{
	//	case AttackType::MELEE:
	//	{
	//		//fighterAttack = std::make_shared<FighterMeleeAttack>();

	//		break;
	//	}

	//	default:
	//	{
	//		std::cout << "Invalid attack type\n";
	//	}
	//}

	//if(fighterAttackPool.size == 0)
	//{

	//}
}
