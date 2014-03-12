#include "Game.h"
#include "Globals.h"

RectangleShape shape(Vector2f(300, 720));
	
Game::Game(void)
{
	enemySpawnTimer = 0;
	shoot = 0;
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	tex = &texture;
	texture.loadFromFile("alus.png");
	player.initialize(Vector2f(268,600), 25, tex, IntRect(0,0,64,64));
}


Game::~Game(void)
{
}


void Game::update(float dt)
{
	updateBullet(dt);
	updateEnemy(dt);
	player.update(dt);
}

void Game::draw(RenderWindow* window)
{		
	for(bit = bEngine.begin(); bit != bEngine.end(); bit++)
	{
		(*bit)->draw(window);
	}

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
	{
		(*eit)->draw(window);
	}

	player.draw(window);
	window->draw(shape);
	window->display();
}

void Game::updateEnemy(float dt)
{
	if(enemySpawnTimer <= 0)
	{
		Enemy *enemy = new Enemy(Vector2f(100,0), 25, tex, IntRect(0,0,64,64));
		enemies.push_back(enemy);
		Enemy *enemy2 = new Enemy(Vector2f(500,0), 25, tex, IntRect(0,0,64,64));
		enemies.push_back(enemy2);
		enemySpawnTimer = 50;
		cout << "Enemy Spawns!!" << endl;
	}
	
	enemySpawnTimer-=dt;

	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt, 90);
		
		if((*eit)->getShootTimer() <= 0)
		{
			BulletEngine *engine1 = new BulletEngine((*eit)->getPosition(), tex, 20);
			bEngine.push_back(engine1);
			(*eit)->setShootTimer(5);
		}
		
		if(!(*eit)->isDead())
			eit++;
		else
		{
			(*eit)->~Enemy();
			eit = enemies.erase(eit);
		}
	}
	
	enemies.shrink_to_fit();

}

void Game::updateBullet(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::Space))
	{
		if(shoot <= 0)
		{	
			BulletEngine *engine1 = new BulletEngine(player.getPosition(),270, tex, 1);
			bEngine.push_back(engine1);
			shoot=0.5;
		}
	}

	shoot-=dt;

	for(bit = bEngine.begin(); bit != bEngine.end();)
	{
		(*bit)->update(dt);
		if (!(*bit)->isEmpty)
		{
			bit++;
		}
		else
		{
			(*bit)->~BulletEngine();
			bit = bEngine.erase(bit);
		}
	}
	
	bEngine.shrink_to_fit();
}