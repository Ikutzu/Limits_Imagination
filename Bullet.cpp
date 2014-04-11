#include "Bullet.h"
#include "Globals.h"

Bullet::Bullet(Vector2f position, float speed, float direction, IntRect sprite) : GameObject(position, sprite)
{
	this->speed = speed;
	hostile = false;
	this->sprite.setRotation(direction);
	angle = direction;
}


Bullet::~Bullet()
{
	
}


void Bullet::update(float dt)
{
	position.x += speed*dt*cos(sprite.getRotation()*degree);
	position.y += speed*dt*sin(sprite.getRotation()*degree);
	
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