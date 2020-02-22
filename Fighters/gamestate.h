#pragma once

#include "game.h"

class GameState
{
public:
	GameState(Game& game);
	virtual void update(double deltaTime) = 0;

	Game& game;
};

