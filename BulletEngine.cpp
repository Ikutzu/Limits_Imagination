#include "BulletEngine.h"
#include "Globals.h"

vector<Bullet*> BulletEngine::bulletL;
vector<Bullet*>::iterator BulletEngine::bit;
vector<Shrapnell*> BulletEngine::shrapnellL;
vector<Shrapnell*>::iterator BulletEngine::shit;

vector<float> BulletEngine::angles;
vector<float>::iterator BulletEngine::ait;
float BulletEngine::angle;

void BulletEngine::clear()
{
	for(bit = bulletL.begin(); bit != bulletL.end(); bit++)
	{
		delete *bit;
	}
	for(shit = shrapnellL.begin(); shit != shrapnellL.end(); shit++)
	{
		delete *shit;
	}
	bulletL.clear();
	shrapnellL.clear();
}

void BulletEngine::shoot(Vector2f pos, float eSpeed, float damage, float eAngle, int ammount)
{
	angle = eAngle;
	for(int i = 0; i < ammount; i++)
	{
		angle += (360/ammount);
		
		if(angle > 360)
		{
			angle = angle-360;
		}
		if(angle <= 0)
		{
			angle = 360+angle;
		}
		

		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		if(*ait <= eAngle)
			angle = eAngle - *ait;
		else
			angle = *ait - eAngle;
		
		angle = 180-angle;

		float bulletspeed =  20;

		bulletspeed = sqrt((bulletspeed*bulletspeed)+(eSpeed*eSpeed)-(2*bulletspeed*eSpeed*cos(angle*degree)));
		angle = sinh((eSpeed*sin(angle*degree))/bulletspeed)/degree;
		
		if(*ait <= eAngle || angle > 270)
		{
				angle = *ait + angle;
		}
		else
		{
				angle = *ait - angle;
		}
		if(bulletspeed == 0)
			angle = 0;
		Bullet *bullet = new Bullet(pos, bulletspeed, 1 , angle, sf::IntRect(64,0,16,16));
		bullet->setHostile();
		bulletL.push_back(bullet);
	}
	angles.clear();
}


void BulletEngine::shoot(Vector2f pos, float speed, float damage, float angle)
{
		Bullet *bullet = new Bullet(pos, speed, damage, angle, sf::IntRect(64,0,16,16));
		bulletL.push_back(bullet);
}

void BulletEngine::shrapnell(Vector2f pos, float eSpeed, float eAngle, int ammount, IntRect sprite)
{
	angle = eAngle;
	for(int i = 0; i < ammount; i++)
	{
		angle += (360/ammount);
		
		if(angle > 360)
		{
			angle = angle-360;
		}
		if(angle <= 0)
		{
			angle = 360+angle;
		}
		

		angles.push_back(angle);
	}
	for(ait = angles.begin(); ait != angles.end(); ait++)
	{
		if(*ait <= eAngle)
			angle = eAngle - *ait;
		else
			angle = *ait - eAngle;
		
		angle = 180-angle;

		float bulletspeed =  20;

		bulletspeed = sqrt((bulletspeed*bulletspeed)+(eSpeed*eSpeed)-(2*bulletspeed*eSpeed*cos(angle*degree)));
		angle = sinh((eSpeed*sin(angle*degree))/bulletspeed)/degree;
		
		if(*ait <= eAngle || angle > 270)
		{
				angle = *ait + angle;
		}
		else
		{
				angle = *ait - angle;
		}
		if(bulletspeed == 0)
			angle = 0;

		sprite.left = 0 + rand()%64;
		sprite.top = 64 + rand()%64;
		sprite.width = 0 + rand()%64 - sprite.left;
		sprite.height = 0 + rand()%64 - sprite.top + 64;

		Shrapnell *bullet = new Shrapnell(pos, bulletspeed, angle, sprite);
		shrapnellL.push_back(bullet);
	}
	angles.clear();
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
			delete *bit;
			bit = bulletL.erase(bit);
		}
	}
	for(shit = shrapnellL.begin(); shit != shrapnellL.end();)
	{
		(*shit)->update(dt);
		
		if (!(*shit)->isDead())
			shit++;
		
		else
		{
			delete *shit;
			shit = shrapnellL.erase(shit);
		}
	}
	
	bulletL.shrink_to_fit();
	shrapnellL.shrink_to_fit();
}

void BulletEngine::draw(RenderWindow* window)
{
	for(bit = bulletL.begin(); bit != bulletL.end(); bit++)
	{
 		(*bit)->draw(window);
	}
	for(shit = shrapnellL.begin(); shit != shrapnellL.end(); shit++)
	{
 		(*shit)->draw(window);
	}
}