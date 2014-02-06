#include "Bullet.h"
#include <cmath>

static const float degree = 3.141592653589793/180;

Bullet::Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	life = 0;
	angle = direction;
	origAngle = angle;
}


Bullet::~Bullet()
{
	
}


void Bullet::update(float dt, float newAngle)
{
	life+=dt;
	
	//changeAngle(newAngle);

	position.x += speed*dt*cos(changeAngle(newAngle)*degree);
	position.y += speed*dt*sin(changeAngle(newAngle)*degree);
	
	sprite.setPosition(position);
}

float Bullet::changeAngle(float newAngle)
{
	if(angle >= 360)
	{
		angle=0+angle-360;
	}
	if(angle < 0)
	{
		angle = 360+angle;
	}
		angle+=sin(degree*newAngle);
		return angle;
}

float const Bullet::returnLife()
{
	return life;
}