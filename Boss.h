#pragma once
#include "gameobject.h"
#include "Player.h"
#include "BulletEngine.h"

#include "SFML\Graphics.hpp"

#include <iostream>

class Boss :
		public GameObject
{
public:
	Boss();
	void initialize(Vector2f position, float speed, IntRect sprite);
	~Boss(void);

	void update(float dt);
	
	void lGunGotHit(float damage);
	void rGunGotHit(float damage);
	void hullGotHit(float damage);

	void killLGun();
	void killRGun();

	bool islgundead();
	bool isrgundead();

	FloatRect Boss::getRGunBorders();
	FloatRect Boss::getLGunBorders();

	void drawBoss(RenderWindow *win);

private:

	float hullHealth, lHealth, rHealth;
	float shootTimer, defShootTimer;
	float encounterTimer;
	float moveTimer, defMoveTimer;
	int phase;
	
	sf::Sprite lgun, rgun;

	bool lgundead, rgundead;


	void moveShip(Vector2f endPosition, float dt);
};

