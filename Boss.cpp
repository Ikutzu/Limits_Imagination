#include "Boss.h"
#include "Globals.h"

Boss::Boss(){}

void Boss::initialize(Vector2f position, float speed, IntRect sprite)
{
	this->position = position;
	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setPosition(this->position);
	
	dead = lgundead = rgundead = false;
	
	this->speed = speed;

	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(90);

	IntRect gunsprite(0,128,64,32);

	lgun.setTexture(*tex);
	lgun.setTextureRect(gunsprite);
	lgun.setPosition(position+Vector2f(-31, this->sprite.getGlobalBounds().height/2));
	lgun.setOrigin(gunsprite.width/2, gunsprite.height/2);
	lgun.setRotation(90);

	gunsprite = IntRect(0,160,64,32);

	rgun.setTexture(*tex);
	rgun.setTextureRect(gunsprite);
	rgun.setPosition(position+Vector2f(31, this->sprite.getGlobalBounds().height/2));
	rgun.setOrigin(gunsprite.width/2, gunsprite.height/2);
	rgun.setRotation(90);

	shootTimer = defShootTimer = 10;
	encounterTimer = 0;
	moveTimer = defMoveTimer = 10;
	phase = 0;

	hullHealth = lHealth = rHealth = 100;
}


Boss::~Boss(void)
{

}

void Boss::update(float dt)
{
	if(dead)
		BulletEngine::shrapnell(this->position, this->speed*-1, this->sprite.getRotation(), 10, sprite.getTextureRect());
	
	encounterTimer += dt;
	shootTimer -=dt;
	moveTimer -= dt;
	/*
	if(encounterTimer >= 200 && encounterTimer < 400)
		phase = 2;
	else if(encounterTimer >= 400)
		phase = 3;
		*/

	switch (phase)
	{
		case 0:
			{
				Vector2f startPos(300,64);
				if(position != startPos)
					moveShip(startPos, dt);
				else
					phase = 1;
				break;
			}
		case 3:
			{
				std::cout << "Phase 3 activated" << std::endl;
				break;
			}
		case 2:
			{
				if(shootTimer <= 0)
				{
					if(!lgundead)
						BulletEngine::shoot(lgun.getPosition(), 15, 2, 90, 10); 
					if(!rgundead)
						BulletEngine::shoot(rgun.getPosition(), 15, 2, 90, 10);

					shootTimer = defShootTimer;
				}
				if(moveTimer <= 0)
				{
					Vector2f startPos(520,64);

					if(position != startPos)
						moveShip(startPos, dt);
					else
					{
						moveTimer = defMoveTimer;
						phase = 1;
					}
				}
				std::cout << "Phase 2 activated" << std::endl;
				break;
			}
		case 1:
			{
				if(shootTimer <= 0)
				{
					if(!lgundead)
						BulletEngine::shoot(lgun.getPosition(), 15, 2, 90, 10); 
					if(!rgundead)
						BulletEngine::shoot(rgun.getPosition(), 15, 2, 90, 10);

					shootTimer = defShootTimer;
				}
				if(moveTimer <= 0)
				{
					Vector2f startPos(80,64);

					if(position != startPos)
						moveShip(startPos, dt);
					else
					{
						moveTimer = defMoveTimer;
						phase = 2;
					}
				}

				std::cout << "Phase 1 activated" << std::endl;
				break;
			}
	}
}

FloatRect Boss::getRGunBorders()
{
	return rgun.getGlobalBounds();
}

FloatRect Boss::getLGunBorders()
{
	return lgun.getGlobalBounds();
}

void Boss::lGunGotHit(float damage)
{
	lHealth -= damage;
	if(lHealth <= 0)
	{
		killLGun();
	}
}
void Boss::rGunGotHit(float damage)
{
	rHealth -= damage;
	if(rHealth <= 0)
	{
		killRGun();
	}
}
void Boss::hullGotHit(float damage)
{
	hullHealth -= damage;

	if(hullHealth <= 0)
	{
		kill();
	}
}

void Boss::killLGun()
{
	lgundead = true;
	BulletEngine::shrapnell(lgun.getPosition(), rand()%25+10, 180, 3, lgun.getTextureRect());
}
void Boss::killRGun()
{
	rgundead = true;
	BulletEngine::shrapnell(rgun.getPosition(), rand()%25+10, 0, 3, rgun.getTextureRect());
}

bool Boss::islgundead()
{
	return lgundead;
}
bool Boss::isrgundead()
{
	return rgundead;
}

void Boss::drawBoss(RenderWindow *win)
{
	if(!dead)
		win->draw(sprite);

	if(!lgundead)
		win->draw(lgun);

	if(!rgundead)
		win->draw(rgun);
}

void Boss::moveShip(Vector2f endPosition, float dt)
{
	if( position.x - endPosition.x <= -1)
		position.x += speed*dt;

	else if(position.x - endPosition.x >= 1)
		position.x -= speed*dt;

	else
	{
		position.x = endPosition.x;
	}


	if( position.y - endPosition.y < -1)
		position.y += speed*dt;
	else if( position.y - endPosition.y > 1)
		position.y -= speed*dt;
	else
	{
		position.y = endPosition.y;
	}
	
	sprite.setPosition(position);
	
	lgun.setPosition(position+Vector2f(-31, this->sprite.getGlobalBounds().height/2));
	rgun.setPosition(position+Vector2f(31, this->sprite.getGlobalBounds().height/2));
}