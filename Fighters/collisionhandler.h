#pragma once

#include <vector>
#include <memory>

class GameObject;
class Collider;

class CollisionHandler
{
public:
	CollisionHandler();
	void handleCollisions(std::vector<std::shared_ptr<GameObject>> gameObjects);

private:
	void handleGameObjectCollisions(GameObject* gameObject1, GameObject* gameObject2);
	void handleGeometryCollisions(GameObject* gameObject1, GameObject* gameObject2, Collider& collider1, Collider& collider2);
};

