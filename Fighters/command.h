#pragma once

class GameObject;

class Command
{
public:
	Command();
	virtual ~Command();

	virtual void execute(GameObject& gameObject) = 0;
	virtual void init();
};

