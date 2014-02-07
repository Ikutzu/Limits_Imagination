#pragma once
#include "gameobject.h"

using namespace sf;

class Bullet :
	public GameObject
{
public:
	Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite);
	~Bullet(void);

	void update(float dt, float newAngle);
	float changeAngle(float newAngle);
	

private:
	float angle;
};

