#include "collisionhandler.h"
#include "gameobject.h"

CollisionHandler::CollisionHandler()
{

}

void CollisionHandler::handleCollisions(std::vector<std::shared_ptr<GameObject>> gameObjects)
{
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
				handleGeometryCollisions(gameObject1, gameObject2, collider1, collider2);
				handleGameObjectCollisions(gameObject1, gameObject2);
			}
		}
	}
}

void CollisionHandler::handleGameObjectCollisions(GameObject* gameObject1, GameObject* gameObject2)
{
	gameObject1->resolveCollision(*gameObject2);
	gameObject2->resolveCollision(*gameObject1);
}

void CollisionHandler::handleGeometryCollisions(GameObject* gameObject1, GameObject* gameObject2, Collider& collider1, Collider& collider2)
{
	Vector2 intersection = collider1.getIntersection(collider2);

	if(intersection.x <= intersection.y)
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
	}
}
