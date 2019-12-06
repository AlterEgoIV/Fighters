#pragma once

class Driver
{
public:
	Driver();
	bool isActive;
	virtual void update(double deltaTime) = 0;
};

