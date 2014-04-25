#pragma once
#include "gameobject.h"
#include "BulletEngine.h"

class Enemy :
	public GameObject
{
public:
	Enemy(Vector2f position, float speed, IntRect sprite);
	~Enemy(void);

	void update(float dt, float newAngle);
	void changeAngle(float newAngle);
	void gotHit(float damage);

private:
	float health;
	float shootTimer;
};

