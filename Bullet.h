#pragma once
#include "gameobject.h"

#include <cmath>

using namespace sf;

class Bullet :
	public GameObject
{
public:
	
	Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite);
	~Bullet(void);

	void update(float dt);
	
	void setHostile();
	bool getHostile();

private:
	bool hostile;
};

