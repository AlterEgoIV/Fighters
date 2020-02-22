#pragma once

#include "gamestate.h"

class MainMenuGameState : public GameState
{
public:
	MainMenuGameState(Game& game);
	void update(double deltaTime) override;
};

