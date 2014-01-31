#include "BulletEngine.h"


BulletEngine::BulletEngine(Texture *tex, int ammount)
{
	angle = 0;
	for(int i = 0; i < ammount; i++)
	{
		angle += 360/ammount;
		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		Bullet *bullet = new Bullet(Vector2f(300,50), 50, *ait, tex, sf::IntRect(0,0,64,64));
		bulletL.push_back(bullet);
	}
	
}


BulletEngine::~BulletEngine(void)
{
}


void BulletEngine::update(float dt)
{
	for(bit = bulletL.begin(); bit != bulletL.end();)
	{
		(*bit)->update(dt);
		
		if ((*bit)->returnLife() < 4)
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
	if (bulletL.begin() == bulletL.end())
	{
	}
}

void BulletEngine::draw(RenderWindow* window)
{
	for(bit = bulletL.begin(); bit != bulletL.end(); bit++)
	{
 		(*bit)->draw(window);
	}
}