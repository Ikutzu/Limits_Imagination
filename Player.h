#pragma once
#include "GameObject.h"
#include "BulletEngine.h"

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player :
	public GameObject
{
public:
	Player();
	~Player(void);

	void update(float dt);
	void initialize(Vector2f position, float speed, IntRect sprite);
	void gotHit();
	void spaceGlue(int action);

	float getHealth();
	float getMaxHealth();

	FloatRect hitbox;

private:

	float health, maxHealth;
	float scale;
	float shoot;

};

