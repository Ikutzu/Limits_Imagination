#include "BulletEngine.h"


BulletEngine::BulletEngine()
{}

BulletEngine::BulletEngine(Vector2f pos, Texture *tex, int ammount)
{
	isEmpty = false;
	
	angle = 0;
	for(int i = 0; i < ammount; i++)
	{
		angle += 360/ammount;
		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		Bullet *bullet = new Bullet(pos, 30, *ait, tex, sf::IntRect(64,0,16,16));
		bulletL.push_back(bullet);
	}
	
}


BulletEngine::~BulletEngine(void)
{
}

void BulletEngine::shoot(Texture *tex, int ammount)
{
	angle = 0;
	for(int i = 0; i < ammount; i++)
	{
		angle += 360/ammount;
		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		Bullet *bullet = new Bullet(Vector2f(300,300), 50, *ait, tex, sf::IntRect(64,0,16,16));
		bulletL.push_back(bullet);
	}
}

void BulletEngine::update(float dt)
{
	for(bit = bulletL.begin(); bit != bulletL.end();)
	{
		(*bit)->update(dt, 10);
		
		if (!(*bit)->isDead())
		{
			bit++;
		}
		else
		{
			(*bit)->~Bullet();
			bit = bulletL.erase(bit);
		}
	}

	bulletL.shrink_to_fit();
	
	if(bulletL.begin() == bulletL.end())
		isEmpty = true;
}

void BulletEngine::draw(RenderWindow* window)
{
	for(bit = bulletL.begin(); bit != bulletL.end(); bit++)
	{
 		(*bit)->draw(window);
	}
}