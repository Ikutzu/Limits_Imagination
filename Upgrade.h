#pragma once
#include "gameobject.h"

class Upgrade :
	public GameObject
{
public:
	Upgrade(Vector2f position, float speed, IntRect sprite, int action);
	~Upgrade(void);

	void update(float dt);
	int getAction();

private:

	int action;
};

