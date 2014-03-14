#include "Bullet.h"
#include "Globals.h"

Bullet::Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite) : GameObject(position, tex, sprite)
{
	
	this->speed = speed;
	hostile = false;
	angle = direction;
	if(angle > 360)
	{
		angle = angle-360;
	}
	if(angle <= 0)
	{
		angle = 360+angle;
	}
}


Bullet::~Bullet()
{
	
}


void Bullet::update(float dt)
{
	position.x += speed*dt*cos(angle*degree);
	position.y += speed*dt*sin(angle*degree);
	
	sprite.setPosition(position);

	if (position.x < GAME_WINDOW.left-16 || position.x > GAME_WINDOW.width+16 ||
		position.y < GAME_WINDOW.top-16  || position.y > GAME_WINDOW.height+16)
		dead = true;
}


void Bullet::setHostile()
{
	hostile = true;
}
bool Bullet::getHostile()
{
	return hostile;
}