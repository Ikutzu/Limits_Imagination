#include "Game.h"
#include "Globals.h"

RectangleShape shape(Vector2f(300, 720));

Font font;		//
Text text;		//

Game::Game(void)
{
	enemySpawnTimer = 0;
	shoot = 0;
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	tex = &texture;
	texture.loadFromFile("alus.png");
	player.initialize(Vector2f(268,600), 25, tex, IntRect(0,0,64,64));

	font.loadFromFile("arial.ttf");		//
	text.setCharacterSize(32);			//
	text.setColor(Color::Red);			//
	text.setFont(font);					//
	text.setStyle(Text::Regular);		//
	text.setPosition(605, 0);			//
	text.setString("Game over!");		//
}


Game::~Game(void)
{
}


void Game::update(float dt)
{
		updateBullet(dt);
		updateEnemy(dt);
	if(!player.isDead())
		player.update(dt);
		collision();
	
}

void Game::draw(RenderWindow* window)
{		
	bulletEngine.draw(window);

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
	{
		(*eit)->draw(window);
	}
	
	window->draw(shape);
	if(!player.isDead())		//
		player.draw(window);	
	else						//
		window->draw(text);		//

	window->display();
}

void Game::updateEnemy(float dt)
{
	if(enemySpawnTimer <= 0)
	{
		Enemy *enemy = new Enemy(Vector2f(100,0), 25, tex, IntRect(0,0,64,64));
		enemies.push_back(enemy);
		//Enemy *enemy2 = new Enemy(Vector2f(500,0), 25, tex, IntRect(0,0,64,64));
		//enemies.push_back(enemy2);
		enemySpawnTimer = 50;
		cout << "Enemy Spawns!!" << endl;
	}
	
	enemySpawnTimer-=dt;

	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt, 90);
		
		if((*eit)->getShootTimer() <= 0)
		{
			bulletEngine.shoot((*eit)->getPosition(), (*eit)->getSpeed(), (*eit)->getAngle(), tex, 40);
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
			bulletEngine.shoot(player.getPosition(), 0, 270, tex);
			shoot=0.5;
		}
	}
	bulletEngine.update(dt);
	shoot-=dt;
}

void Game::collision()
{
	for(bit = bulletEngine.bulletL.begin(); bit != bulletEngine.bulletL.end(); bit++)
	{
		for(eit = enemies.begin(); eit != enemies.end(); eit++)
		{
			if((*eit)->getBorders().intersects((*bit)->getBorders()) && !(*bit)->getHostile())
			{
				(*eit)->kill();
				(*bit)->kill();
			}
		}
		
		if(player.hitbox.intersects((*bit)->getBorders()) && (*bit)->getHostile())
			player.kill();
	}
}