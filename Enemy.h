#pragma once
#include "gameobject.h"

class Enemy :
	public GameObject
{
public:
	Enemy(Vector2f position, float speed, Texture *tex, IntRect sprite);
	~Enemy(void);

	void update(float dt, float newAngle);
	float changeAngle(float newAngle);
	float getShootTimer();
	void setShootTimer(float time);

private:
	float health;
	float angle;
	float shootTimer;
};

