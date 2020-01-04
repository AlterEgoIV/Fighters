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
	// Update game objects
	for(auto& gameObject : gameObjects)
	{
		gameObject->update(deltaTime);
		renderer.appendToDrawList(*gameObject->shape);
	}

	// Handle game object collisions
	for(int i = 0; i < gameObjects.size() - 1; ++i)
	{
		for(int j = i + 1; j < gameObjects.size(); ++j)
		{
			GameObject* gameObject1 = gameObjects[i].get();
			GameObject* gameObject2 = gameObjects[j].get();
			Collider collider1 = gameObject1->collider;
			Collider collider2 = gameObject2->collider;

			if(collider1.collidesWith(collider2))
			{
				//std::cout << "Objects colliding\n";

				Vector2 intersection = collider1.getIntersection(collider2);

				/*if(intersection.x <= intersection.y)
				{
					if(gameObject1->position.x <= gameObject2->position.x)
					{
						gameObject1->position.x -= intersection.x;
					}
					else
					{
						gameObject1->position.x += intersection.x;
					}
				}
				else
				{
					if(gameObject1->position.y <= gameObject2->position.y)
					{
						gameObject1->position.y -= intersection.y;
					}
					else
					{
						gameObject1->position.y += intersection.y;
					}
				}*/

				if(intersection.x <= intersection.y)
				{
					if(gameObject2->position.x <= gameObject1->position.x)
					{
						gameObject2->position.x -= intersection.x;
					}
					else
					{
						gameObject2->position.x += intersection.x;
					}
				}
				else
				{
					if(gameObject2->position.y <= gameObject1->position.y)
					{
						gameObject2->position.y -= intersection.y;
					}
					else
					{
						gameObject2->position.y += intersection.y;
					}
				}
			}

			/*if(gameObject1->collidesWith(*gameObject2))
			{
				gameObject1->resolveCollision(*gameObject2);
				gameObject2->resolveCollision(*gameObject1);
			}*/
		}
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
