#pragma once
#include "gameobject.h"
class Enemy :
	public GameObject
{
public:
	Enemy(Vector2f position, float speed, Texture *tex, IntRect sprite);
	~Enemy(void);
};

