#pragma once

#include "gamestate.h"
#include "world.h"

class PlayGameState : public GameState
{
public:
	PlayGameState(Game& game);
	void update(double deltaTime) override;

	World world;
};

