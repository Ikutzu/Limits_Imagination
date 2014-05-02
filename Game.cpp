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
	gameTimer = 0;
}


Game::~Game(void)
{
	BulletEngine::clear();
}

void Game::update(float dt)
{
	cout << score << endl;
	if(Keyboard::isKeyPressed(Keyboard::P))
	{
		SceneSystem::changeScene(new Pausemenu);
	}
	updateBullet(dt);
	updateEnemy(dt);
	updateUpgrades(dt);
	collision();
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
	
	

}

void Game::draw(RenderWindow* window)
{		
	window->draw(_background);

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
		(*eit)->draw(window);
	
	BulletEngine::draw(window);

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
	if(enemySpawnTimer <= 0 && gameTimer <= 600)
	{
		//for(int i=0; i<3; i++)
		//{
			Enemy *enemy = new Enemy(Vector2f(rand()%536 + 32,0), 15, IntRect(0,64,64,64));
			enemies.push_back(enemy);
		//}
		enemySpawnTimer = 5;
		cout << "Enemy Spawns!!" << endl;
	}
	
	gameTimer += dt;
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
				Upgrade *upgrade = new Upgrade((*eit)->getPosition(), 10, rand()%4+1);
				upgrades.push_back(upgrade);
			}
			
			delete *eit;
			eit = enemies.erase(eit);
			score += 100;
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
			delete *uit;
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
				(*eit)->gotHit((*bit)->getDamage());
				(*bit)->kill();
			}
			if((*eit)->getBorders().intersects(player.hitbox) && !player.isDead())
			{
				(*eit)->kill();
				player.gotHit(2);
				updateHealthBar();
			}
			/*
			for(shit = BulletEngine::shrapnellL.begin(); shit != BulletEngine::shrapnellL.end(); shit++)
			{
				if((*eit)->getBorders().intersects((*shit)->getBorders()))
				{
					IntRect tesmi;
					tesmi.left = (*shit)->getBorders().left;
					tesmi.top = (*shit)->getBorders().top;
					tesmi.width = (*shit)->getBorders().width;
					tesmi.height = (*shit)->getBorders().height;
					
					Vector2f vectortesmi(4,4);// = (*shit)->getPosition();
					float nopeustesmi = 10;//(*shit)->getSpeed();
					float rotatiotesmi = 10;//(*shit)->getRotation();
					

					//BulletEngine::shrapnell(vectortesmi, nopeustesmi, rotatiotesmi, 20, tesmi);
					(*shit)->kill();
				}
			}*/
			
		}
		if(player.hitbox.intersects((*bit)->getBorders()) && (*bit)->getHostile() && !player.isDead())
		{
			(*bit)->kill();
			player.gotHit((*bit)->getDamage());
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
	int width = 250*(player.getHealth()/player.getMaxHealth());
	if (width < 0 || width > 250)
		width = 0;

	healthBar->changeSpriteRect(IntRect(80,0,width,64));
}