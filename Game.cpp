#include "Game.h"
#include "Globals.h"

RectangleShape shape(Vector2f(300, 720));

Font font;			//
Text gameover;		//
Text youwin;
Text scoretext;

Game::Game(void)
{
	background.loadFromFile("gamebackground.png");
	_background.setTexture(background);
	tex = &texture;
	texture.loadFromFile("game.png");
	GameObject::setTexture(tex);
	
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	player.initialize(Vector2f(300,600), 25, IntRect(0,0,64,64));
	
	healthBar = new GameObject(Vector2f(625, 631), IntRect(80,0,250,64));
	healthBarBackground.setTexture(texture);
	healthBarBackground.setTextureRect(IntRect(64,64,266,80));
	healthBarBackground.setPosition(Vector2f(617, 623));
	
	boss.initialize(Vector2f(300, -128), 10, IntRect(224,144,105,98));

	font.loadFromFile("arial.ttf");		//
	
	gameover.setCharacterSize(32);			//
	gameover.setColor(Color::Red);			//
	gameover.setFont(font);					//
	gameover.setStyle(Text::Regular);		//
	gameover.setPosition(250, 330);			//
	gameover.setString("Game over!");		//
	
	youwin.setCharacterSize(32);			//
	youwin.setColor(Color::Green);			//
	youwin.setFont(font);					//
	youwin.setStyle(Text::Regular);		//
	youwin.setPosition(250, 330);			//
	youwin.setString("You Win!");

	scoretext.setCharacterSize(32);
	scoretext.setColor(Color::Black);
	scoretext.setFont(font);
	scoretext.setStyle(Text::Regular);
	scoretext.setPosition(605, 40);
	
	score = 0;
	bossTime = 50; /////////////////////////
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
	ostringstream scorething;
	scorething << score;
	scoretext.setString("Score: " + scorething.str());

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
		if(deadtimer > 30)
		{
			SceneSystem::closeScene();
		}
		deadtimer += dt;
	}
	else
		player.update(dt);

	if(boss.isDead())
	{
		if(deadtimer > 30)
		{
			SceneSystem::closeScene();
		}
		deadtimer += dt;
	}
}

void Game::draw(RenderWindow* window)
{		
	window->draw(_background);

	for(eit=enemies.begin(); eit != enemies.end(); eit++)
		(*eit)->draw(window);
	
	BulletEngine::draw(window);

	if(gameTimer > bossTime && !boss.isDead())
		boss.drawBoss(window);
	
	for(uit=upgrades.begin(); uit != upgrades.end(); uit++)
		(*uit)->draw(window);
	
	window->draw(shape);
	window->draw(healthBarBackground);
	healthBar->draw(window);

	if(!player.isDead())			//
		player.draw(window);	
	else							//
		window->draw(gameover);		//

	if(boss.isDead())
		window->draw(youwin);

	window->draw(scoretext);

}

void Game::updateEnemy(float dt)
{
	gameTimer += dt;
	enemySpawnTimer-=dt;


	if(enemySpawnTimer <= 0 && gameTimer <= bossTime)
	{
		//for(int i=0; i<3; i++)
		//{
			Enemy *enemy = new Enemy(Vector2f(rand()%536 + 32,0), 15, IntRect(0,64,64,64));
			enemies.push_back(enemy);
		//}
		enemySpawnTimer = 5;
		cout << "Enemy Spawns!!" << endl;
	}
	
	if(gameTimer > bossTime && !boss.isDead()) //////////////////////////////////////////
	{
		boss.update(dt);
	}


	for(eit=enemies.begin(); eit != enemies.end(); )
	{
		(*eit)->update(dt, 90);
		
		if(!(*eit)->isDead())
			eit++;
		else
		{
			if(rand()%10 == 0)
			{
				Upgrade *upgrade = new Upgrade((*eit)->getPosition(), 10, rand()%5+1);
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
				score -= 50;
			}
		}
		if(player.hitbox.intersects((*bit)->getBorders()) && (*bit)->getHostile() && !player.isDead())
		{
			(*bit)->kill();
			player.gotHit((*bit)->getDamage());
			updateHealthBar();
			score -= 10;
		}
		if(gameTimer > bossTime)
		{
			if(boss.getLGunBorders().intersects((*bit)->getBorders()) && !(*bit)->getHostile() && !boss.islgundead())
			{
				(*bit)->kill();
				boss.lGunGotHit((*bit)->getDamage());
			}
			if(boss.getRGunBorders().intersects((*bit)->getBorders()) && !(*bit)->getHostile() && !boss.isrgundead())
			{
				(*bit)->kill();
				boss.rGunGotHit((*bit)->getDamage());
			}
			if(boss.getBorders().intersects((*bit)->getBorders()) && !(*bit)->getHostile())
			{
				(*bit)->kill();
				boss.hullGotHit((*bit)->getDamage());
			}
		}
	}
	
	auto thingmabob = upgrades;

	for(uit = thingmabob.begin(); uit != thingmabob.end(); uit++)
	{
		if((*uit)->getBorders().intersects(player.hitbox))
		{
			score += 500;
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