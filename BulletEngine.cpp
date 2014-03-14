#include "BulletEngine.h"
#include "Globals.h"


BulletEngine::BulletEngine()
{}

BulletEngine::~BulletEngine(void)
{
}

void BulletEngine::shoot(Vector2f pos, float speed, float eangle, Texture *tex, int ammount)
{
	angle = eangle;
	for(int i = 0; i < ammount; i++)
	{
		angle += (360/ammount);
		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		angle = eangle - *ait;
		if(angle > 360)
		{
			angle = angle-360;
		}
		if(angle <= 0)
		{
			angle = 360+angle;
		}

		float enemyspeed = 30;
		if(angle != 90.00000 && angle != 270.00000)
			enemyspeed += (enemyspeed-speed)*cos(angle*degree);
		Bullet *bullet = new Bullet(pos, enemyspeed, *ait, tex, sf::IntRect(64,0,16,16));
		bullet->setHostile();
		bulletL.push_back(bullet);
	}
	angles.clear();
}

void BulletEngine::shoot(Vector2f pos, float speed, float angle, Texture *tex)
{
		Bullet *bullet = new Bullet(pos, speed, angle, tex, sf::IntRect(64,0,16,16));
		bulletL.push_back(bullet);
}

void BulletEngine::update(float dt)
{
	for(bit = bulletL.begin(); bit != bulletL.end();)
	{
		(*bit)->update(dt, 10);
		
		if (!(*bit)->isDead())
			bit++;
		
		else
		{
			(*bit)->~Bullet();
			bit = bulletL.erase(bit);
		}
	}

	bulletL.shrink_to_fit();
}

void BulletEngine::draw(RenderWindow* window)
{
	for(bit = bulletL.begin(); bit != bulletL.end(); bit++)
	{
 		(*bit)->draw(window);
	}
}