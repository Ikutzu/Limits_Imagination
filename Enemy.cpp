#include "Enemy.h"
#include "Globals.h"


Enemy::Enemy(Vector2f position, float speed, IntRect sprite) : GameObject(position, sprite)
{
	this->speed = speed;
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(90);
	shootTimer = 5;
	health = 3;
}


Enemy::~Enemy(void)
{
}


void Enemy::update(float dt, float newAngle)
{
	if(dead)
		BulletEngine::shrapnell(this->position, this->speed*-1, this->sprite.getRotation(), 8, sprite.getTextureRect());
	
	else{
	changeAngle(newAngle*dt*0.05);
	position.x += speed*dt*cos(getRotation()*degree);
	position.y += speed*dt*sin(getRotation()*degree);

	sprite.setPosition(position);

	if (position.x < GAME_WINDOW.left-64 || position.x > GAME_WINDOW.width+64 ||
		position.y < GAME_WINDOW.top-64  || position.y > GAME_WINDOW.height+64)
		dead = true;
	if(shootTimer <= 0)
		{
			BulletEngine::shoot(this->position, this->speed, 1, this->sprite.getRotation(), 4);
			shootTimer = 15;
		}
	shootTimer -= dt;
	}
}

void Enemy::changeAngle(float newAngle)
{
	
	if(position.x < 300)
		sprite.setRotation(sprite.getRotation() -newAngle);
	if(position.x > 300)
		sprite.setRotation(sprite.getRotation()+ newAngle);
		
}

void Enemy::gotHit(float damage)
{
	health -= damage;

	if(health <= 0)
		kill();
}