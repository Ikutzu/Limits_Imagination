#include "Bullet.h"
#include "Globals.h"
#include <cmath>

Bullet::Bullet(Vector2f position, float speed, float direction, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	angle = direction;
}


Bullet::~Bullet()
{
	
}


void Bullet::update(float dt, float newAngle)
{	
	position.x += speed*dt*cos(changeAngle(newAngle)*degree);
	position.y += speed*dt*sin(changeAngle(newAngle)*degree);
	
	sprite.setPosition(position);

	if (position.x < GAME_WINDOW.left-16 || position.x > GAME_WINDOW.width+16 ||
		position.y < GAME_WINDOW.top-16  || position.y > GAME_WINDOW.height+16)
		dead = true;
}

float Bullet::changeAngle(float newAngle)
{
	if(angle > 360)
	{
		angle = angle-360;
	}
	if(angle <= 0)
	{
		angle = 360+angle;
	}
	
		return angle;
}