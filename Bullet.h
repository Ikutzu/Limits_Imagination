#pragma once
#include "gameobject.h"
class Bullet :
	public GameObject
{
public:
	Bullet(sf::Vector2f position, float speed, float direction, sf::Texture *tex, sf::IntRect sprite);
	~Bullet(void);

	void Update(float dt);

private:
	float angle;
};

