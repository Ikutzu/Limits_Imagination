#include "BulletEngine.h"
#include "Globals.h"


BulletEngine::BulletEngine()
{}

BulletEngine::~BulletEngine(void)
{
}

void BulletEngine::shoot(Vector2f pos, float eSpeed, float eAngle, Texture *tex, int ammount)
{
	angle = eAngle;
	for(int i = 0; i < ammount; i++)
	{
		angle += (360/ammount);
		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		angle = *ait - eAngle;
		if(angle > 360)
		{
			angle = angle-360;
		}
		if(angle <= 0)
		{
			angle = 360+angle;
		}

		float bulletspeed = 30;
		float enemyspeed  = 0;
		
		enemyspeed = (eSpeed)*cos(angle*degree);
		
		//angle = eAngle+(cos((bulletspeed*bulletspeed-eSpeed*eSpeed-enemyspeed*enemyspeed)/((-2)*eSpeed*enemyspeed))/degree);
		
		Bullet *bullet = new Bullet(Vector2f(300,360), bulletspeed+enemyspeed, *ait, tex, sf::IntRect(64,0,16,16));
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
		(*bit)->update(dt);
		
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