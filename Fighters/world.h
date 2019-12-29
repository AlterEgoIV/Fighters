#pragma once

#include <memory>
#include <vector>

#include "renderer.h"

class GameObject;
class FighterAttack;
class Fighter;

class World
{
private:
	void createGameObjects();
	std::vector<std::shared_ptr<Fighter>> createFighters();

	std::vector<std::shared_ptr<GameObject>> gameObjects;
	std::vector<std::shared_ptr<GameObject>> gameObjectsToAdd;
	std::vector<std::shared_ptr<FighterAttack>> fighterAttackPool;
	Renderer& renderer;

public:
	World(Renderer& renderer);

	void update(double deltaTime);
	void createFighterAttack(Fighter& fighter);
};

