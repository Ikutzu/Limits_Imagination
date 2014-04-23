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
	GameObject::setTexture(tex);
	
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	player.initialize(Vector2f(268,600), 25, IntRect(0,0,64,64));
	
	healthBar = new GameObject(Vector2f(625, 631), IntRect(80,0,250,64));
	healthBarBackground.setTexture(texture);
	healthBarBackground.setTextureRect(IntRect(64,64,266,80));
	healthBarBackground.setPosition(Vector2f(617, 623));

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
	updateUpgrades(dt);

	if(player.isDead())
	{
		if(deadtimer > 15)
		{
			SceneSystem::closeScene();
		}
		deadtimer += dt;
	}
	else
		player.update(dt);
	
	collision();

}

void Game::draw(RenderWindow* window)
{		
	window->draw(_background);
	BulletEngine::draw(window);

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
		(*eit)->draw(window);

	for(uit=upgrades.begin(); uit != upgrades.end(); uit++)
		(*uit)->draw(window);
	
	window->draw(shape);
	window->draw(healthBarBackground);
	healthBar->draw(window);

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
			Enemy *enemy = new Enemy(Vector2f(rand()%536 + 32,0), 15, IntRect(0,64,64,64));
			enemies.push_back(enemy);
		//}
		enemySpawnTimer = 5;
		cout << "Enemy Spawns!!" << endl;
	}
	
	enemySpawnTimer-=dt;

	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt, 90);
		
		if(!(*eit)->isDead())
			eit++;
		else
		{
			if(rand()%10 == 0)
			{
				Upgrade *upgrade = new Upgrade((*eit)->getPosition(), 10, IntRect(0,128,32,32), 1);
				upgrades.push_back(upgrade);
			}
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

void Game::updateUpgrades(float dt)
{
	for( uit = upgrades.begin(); uit != upgrades.end();)
	{
		(*uit)->update(dt);

		if(!(*uit)->isDead())
			uit++;
		else
		{
			(*uit)->~Upgrade();
			uit = upgrades.erase(uit);
		}
	}

	upgrades.shrink_to_fit();
	
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
		{
			(*bit)->kill();
			player.gotHit();
			updateHealthBar();
		}
	}
	
	auto thingmabob = upgrades;

	for(uit = thingmabob.begin(); uit != thingmabob.end(); uit++)
	{
		if((*uit)->getBorders().intersects(player.hitbox))
		{
			player.spaceGlue((*uit)->getAction());
			(*uit)->kill();
			updateHealthBar();
		}
	}
	
}

void Game::updateHealthBar()
{
	healthBar->changeSpriteRect(IntRect(80,0,250*(player.getHealth()/player.getMaxHealth()),64));
}