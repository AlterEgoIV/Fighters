#include "fighteraidriver.h"
#include "fighter.h"

FighterAIDriver::FighterAIDriver(Fighter& fighter, Fighter& target) : fighter{fighter}, target{target}
{

}

void FighterAIDriver::update(double deltaTime)
{
	if(isActive)
	{
		direction.set(Vector2::subtract(target.position, fighter.position).normalise());
		fighter.position.add(direction.scale(fighter.speed * deltaTime));

		if(fabs(fighter.position.x - target.position.x) > fabs(fighter.position.y - target.position.y))
		{
			if(fighter.position.x < target.position.x)
			{
				fighter.attackDirection.set(1, 0);
				//fighter.attackCollider.shape.setSize(Vector2(fighter.size.x, fighter.size.y));
				//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
				//fighter.attackCollider.shape.setPosition(fighter.position.x + fighter.size.x / 2 + fighter.attackCollider.shape.getSize().x / 2, fighter.position.y);
			}

			if(fighter.position.x > target.position.x)
			{
				fighter.attackDirection.set(-1, 0);
				//fighter.attackCollider.shape.setSize(Vector2(fighter.size.x, fighter.size.y));
				//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
				//fighter.attackCollider.shape.setPosition(fighter.position.x - fighter.size.x / 2 - fighter.attackCollider.shape.getSize().x / 2, fighter.position.y);
			}
		}
		else
		{
			if(fighter.position.y < target.position.y)
			{
				fighter.attackDirection.set(0, 1);
				//fighter.attackCollider.shape.setSize(Vector2(fighter.size.y, fighter.size.x));
				//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
				//fighter.attackCollider.shape.setPosition(fighter.position.x, fighter.position.y + fighter.size.y / 2 + fighter.attackCollider.shape.getSize().y / 2);
			}

			if(fighter.position.y > target.position.y)
			{
				fighter.attackDirection.set(0, -1);
				//fighter.attackCollider.shape.setSize(Vector2(fighter.size.y, fighter.size.x));
				//fighter.attackCollider.shape.setOrigin(fighter.attackCollider.shape.getSize().x / 2, fighter.attackCollider.shape.getSize().y / 2);
				//fighter.attackCollider.shape.setPosition(fighter.position.x, fighter.position.y - fighter.size.y / 2 - fighter.attackCollider.shape.getSize().y / 2);
			}
		}
	}
}
