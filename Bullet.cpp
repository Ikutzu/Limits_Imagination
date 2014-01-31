#include "Bullet.h"
#include <cmath>

static const float degree = 3.141592653589793/180;

Bullet::Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	life = 0;
	angle = direction;
}


Bullet::~Bullet()
{
	
}


void Bullet::update(float dt)
{
	life+=dt;

	position.x += speed*dt*cos(angle*degree);
	position.y += speed*dt*sin(angle*degree);
	
	sprite.setPosition(position);

	if(life > 4)
	{
		
	}
}

float const Bullet::returnLife()
{
	return life;
}