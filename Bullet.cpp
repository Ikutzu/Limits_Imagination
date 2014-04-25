#include "Bullet.h"
#include "Globals.h"

Bullet::Bullet(Vector2f position, float speed, float damage, float direction, IntRect sprite) : GameObject(position, sprite)
{
	this->speed = speed;
	this->damage = damage;
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	hostile = false;
	this->sprite.setRotation(direction);
	angle = direction;
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
float Bullet::getDamage()
{
	return damage;
}