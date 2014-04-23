#include "Upgrade.h"
#include "Globals.h"


Upgrade::Upgrade(Vector2f position, float speed, IntRect sprite, int action) : GameObject(position, sprite)
{
	this->speed = speed;
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->action = action;
	this->sprite.setRotation(90);
}

Upgrade::~Upgrade(void)
{
}

void Upgrade::update(float dt)
{
	position.x += speed*dt*cos(getRotation()*degree);
	position.y += speed*dt*sin(getRotation()*degree);

	sprite.setPosition(position);

	if (position.x < GAME_WINDOW.left-64 || position.x > GAME_WINDOW.width+64 ||
		position.y < GAME_WINDOW.top-64  || position.y > GAME_WINDOW.height+64)
		dead = true;
}

int Upgrade::getAction()
{
	return action;
}