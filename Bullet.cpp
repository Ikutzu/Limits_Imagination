#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f position, float speed, float angle, sf::Texture *tex, sf::IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	this->angle = angle;
}


Bullet::~Bullet(void)
{
}


void Bullet::Update(float dt)
{
	position.x += speed*dt*cos(angle);
	position.y += speed*dt*sin(angle);
}