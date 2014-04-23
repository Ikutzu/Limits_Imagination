#pragma once
#include "Scene.h"
#include "SceneSystem.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Upgrade.h"
#include "BulletEngine.h"
#include "Pausemenu.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class Game:
	public Scene
{
public:
	Game(void);
	~Game(void);

	void update(float dt);
	void draw(RenderWindow* window);

private:
	
	Sprite _background;
	Texture background;

	Texture texture;
	Texture* tex;

	float enemySpawnTimer;
	float deadtimer;

	Player player;
	GameObject* healthBar;
	Sprite healthBarBackground;

	float score;

	vector<Enemy*> enemies;
	vector<Enemy*>::iterator eit;
	
	vector<Upgrade*> upgrades;
	vector<Upgrade*>::iterator uit;

	vector<Bullet*>::iterator bit;

	void updateEnemy(float dt);
	void updateBullet(float dt);
	void updateUpgrades(float dt);
	void updateHealthBar();
	void collision();
};

