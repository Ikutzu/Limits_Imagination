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

private:
	float health;
	float angle;
	float shootTimer;
};

