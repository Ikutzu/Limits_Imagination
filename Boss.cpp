#include "Boss.h"


Boss::Boss(Vector2f position, float speed, IntRect sprite) : GameObject(position, sprite)
{
	this->speed = speed;
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(90);
	shootTimer = 5;
	moveTimer = 1;
	encounterTimer = 0;
	health = 100;
}


Boss::~Boss(void)
{

}

void Boss::update(float dt)
{
	

}

void gotHit(float damage)
{
	
}