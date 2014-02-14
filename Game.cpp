#include "Game.h"

RectangleShape shape(Vector2f(300, 720));
	
Game::Game(void)
{
	enemySpawnTimer = 0;
	shoot = 0;
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	tex = &texture;
	texture.loadFromFile("alus.png");
	player.initialize(Vector2f(268,600), 40, tex, IntRect(0,0,64,64));
}


Game::~Game(void)
{
}


void Game::update(float dt)
{
	if(enemySpawnTimer <= 0)
	{
		Enemy *enemy = new Enemy(Vector2f(100,100), 30, tex, IntRect(0,0,64,64));
		enemies.push_back(enemy);
		enemySpawnTimer = 50;
		cout << "Enemy Spawns!!" << endl;
	}
	if(Keyboard::isKeyPressed(Keyboard::Space))
	{
		if(shoot <= 0)
		{
			BulletEngine *engine1 = new BulletEngine(tex, 20);
			bEngine.push_back(engine1);
			shoot=1;
		}
	}

	shoot-=dt;
	enemySpawnTimer-=dt;

	for(bIt = bEngine.begin(); bIt != bEngine.end();)
	{
		(*bIt)->update(dt);
		if (!(*bIt)->isEmpty)
		{
			bIt++;
		}
		else
		{
			(*bIt)->~BulletEngine();
			bIt = bEngine.erase(bIt);
		}
	}
	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt,3);
		if(!(*eit)->isDead())
			eit++;
		else
		{
			(*eit)->~Enemy();
			eit = enemies.erase(eit);
		}
	}
	
	bEngine.shrink_to_fit();
	enemies.shrink_to_fit();

	player.update(dt);
}

void Game::draw(RenderWindow* window)
{		
	player.draw(window);
	for(bIt = bEngine.begin(); bIt != bEngine.end(); bIt++)
	{
		(*bIt)->draw(window);
	}
	for(eit=enemies.begin(); eit != enemies.end(); eit++)
	{
		(*eit)->draw(window);
	}
	window->draw(shape);
	window->display();
}