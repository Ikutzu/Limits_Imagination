#include "Enemy.h"
#include "Bullet.h"
#include "Globals.h"


Enemy::Enemy(Vector2f position, float speed, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	angle = 45;
	this->sprite.setRotation(angle+90);
	shootTimer=0;
}


Enemy::~Enemy(void)
{
}


void Enemy::update(float dt, float newAngle)
{
	position.x += speed*dt*cos(changeAngle(newAngle)*degree);
	position.y += speed*dt*sin(changeAngle(newAngle)*degree);
	
	sprite.setPosition(position);
	if(shootTimer <= 0)
	{
		//Bullet *bullet = new Bullet(position, 40, angle, tex, IntRect(64,0,16,16));
	}
}

float Enemy::changeAngle(float newAngle)
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