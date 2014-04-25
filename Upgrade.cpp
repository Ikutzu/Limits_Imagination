#include "Upgrade.h"
#include "Globals.h"


Upgrade::Upgrade(Vector2f position, float speed, int action) : GameObject(position, IntRect(0,0,0,0))
{
	this->speed = speed;
	this->action = action;
	
	switch (action)
	{
	case 1: // recover health
		{
			sprite.setTextureRect(IntRect(64,144,32,32));
			break;
		}
	case 2: // increase health
		{
			sprite.setTextureRect(IntRect(96,144,32,32));
			break;
		}
	case 3: // faster shooting
		{
			sprite.setTextureRect(IntRect(128,144,32,32));
			break;
		}
	case 4: // faster movement
		{
			sprite.setTextureRect(IntRect(160,144,32,32));
			break;
		}
	}

	this->sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
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