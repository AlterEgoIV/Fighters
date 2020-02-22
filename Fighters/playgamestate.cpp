#include "playgamestate.h"

PlayGameState::PlayGameState(Game& game) : GameState(game), world(game.renderer)
{

}

void PlayGameState::update(double deltaTime)
{
	world.update(deltaTime);
}