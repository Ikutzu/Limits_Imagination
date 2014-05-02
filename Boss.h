#pragma once
#include "gameobject.h"

class Boss :
		public GameObject
{
public:
	Boss(Vector2f position, float speed, IntRect sprite);
	~Boss(void);

	void update(float dt);
	void gotHit(float damage);

private:
	float health;
	float shootTimer;
	float moveTimer, encounterTimer;
};

