#include "Game.h"
#include "Globals.h"

RectangleShape shape(Vector2f(300, 720));

Font font;		//
Text text;		//


Game::Game(void)
{
	background.loadFromFile("gamebackground.png");
	_background.setTexture(background);
	tex = &texture;
	texture.loadFromFile("game.png");

	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	player.initialize(Vector2f(268,600), 25, tex, IntRect(0,0,64,64));

	font.loadFromFile("arial.ttf");		//
	text.setCharacterSize(32);			//
	text.setColor(Color::Red);			//
	text.setFont(font);					//
	text.setStyle(Text::Regular);		//
	text.setPosition(605, 0);			//
	text.setString("Game over!");		//
	
	score = 0;
	enemySpawnTimer = 0;
	deadtimer = 0;
}


Game::~Game(void)
{
	BulletEngine::clear();
}

void Game::update(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::P))
	{
		SceneSystem::changeScene(new Pausemenu);
	}
	updateBullet(dt);
	updateEnemy(dt);
	player.update(dt);
	if(player.isDead())
	{
		if(deadtimer > 15)
		{
			SceneSystem::closeScene();
		}
		deadtimer += dt;
	}
	collision();
}

void Game::draw(RenderWindow* window)
{		
	window->draw(_background);
	BulletEngine::draw(window);

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
	{
		(*eit)->draw(window);
	}
	
	window->draw(shape);

	if(!player.isDead())		//
		player.draw(window);	
	else						//
		window->draw(text);		//

}

void Game::updateEnemy(float dt)
{
	if(enemySpawnTimer <= 0)
	{
		//for(int i=0; i<3; i++)
		//{
			Enemy *enemy = new Enemy(Vector2f(rand()%600,0), 15, tex, IntRect(0,0,64,64));
			enemies.push_back(enemy);
		//}
		enemySpawnTimer = 5;
		cout << "Enemy Spawns!!" << endl;
	}
	
	enemySpawnTimer-=dt;

	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt, 90);
		
		if((*eit)->getShootTimer() <= 0)
		{
			BulletEngine::shoot((*eit)->getPosition(), (*eit)->getSpeed(), (*eit)->getRotation(), tex, 40);
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
	BulletEngine::update(dt);
}

void Game::collision()
{
	for(bit = BulletEngine::bulletL.begin(); bit != BulletEngine::bulletL.end(); bit++)
	{
		for(eit = enemies.begin(); eit != enemies.end(); eit++)
		{
			if((*eit)->getBorders().intersects((*bit)->getBorders()) && !(*bit)->getHostile())
			{
				score += 100;
				(*eit)->kill();
				(*bit)->kill();
			}
		}
		
		if(player.hitbox.intersects((*bit)->getBorders()) && (*bit)->getHostile() && !player.isDead())
			player.kill();
	}
}