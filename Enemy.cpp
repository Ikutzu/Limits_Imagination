#include "Enemy.h"
#include "Globals.h"


Enemy::Enemy(Vector2f position, float speed, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
	angle = 90;
	this->sprite.setRotation(angle+90);
	shootTimer=0;
}


Enemy::~Enemy(void)
{
}


void Enemy::update(float dt, float newAngle)
{
	position.x += speed*dt*cos(changeAngle(newAngle*dt)*degree);
	position.y += speed*dt*sin(changeAngle(newAngle*dt)*degree);

	sprite.setPosition(position);
	
	if (position.x < GAME_WINDOW.left-64 || position.x > GAME_WINDOW.width+64 ||
		position.y < GAME_WINDOW.top-64  || position.y > GAME_WINDOW.height+64)
		dead = true;

	shootTimer -= dt;
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
	}/*
	if(position.x > 300)
		angle -= degree*newAngle;
	if(position.x < 300)
		angle += degree*newAngle;
		*/
		return angle;
}

float Enemy::getShootTimer()
{
	return shootTimer;
}

void Enemy::setShootTimer(float time)
{
	shootTimer = time;
}