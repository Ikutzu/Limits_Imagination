#pragma once
#include "gameobject.h"

class Shrapnell :
	public GameObject
{
public:
	Shrapnell(Vector2f position, float speed, float direction, IntRect sprite);
	~Shrapnell(void);

	void update(float dt);

private:

	float angle;
	float spin;
	float damage;
};