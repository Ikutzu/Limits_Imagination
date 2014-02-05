#pragma once
#include "gameobject.h"

using namespace sf;

class Bullet :
	public GameObject
{
public:
	Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite);
	~Bullet(void);

	float const returnLife();
	void update(float dt, float newAngle);
	float changeAngle(float newAngle);

private:
	float angle;
	float life;
	float origAngle;
};

