#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletEngine.h"
#include "Globals.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Game
{
public:
	Game(void);
	~Game(void);

	void update(float dt);
	void draw(RenderWindow* window);
	

private:

	Texture texture;
	Texture* tex;

	float enemySpawnTimer;
	float shoot;
	
	Player player;
	
	vector<Enemy*> enemies;
	vector<Enemy*>::iterator eit;
	
	BulletEngine bulletEngine;
	
	vector<BulletEngine*> bEngine;
	vector<BulletEngine*>::iterator bIt;

	void updateEnemy(float dt);
	void updateBullet(float dt);
};
