#include "Player.h"
#include "Globals.h"

Player::Player()
{}

Player::~Player(void)
{}

void Player::update(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::A) && position.x > GAME_WINDOW.left+this->getBorders().width * 0.5)
		{
			position.x -= 1*speed*dt;
		}
	if(Keyboard::isKeyPressed(Keyboard::D) && position.x < GAME_WINDOW.width-this->getBorders().width * 0.5)
		{
			position.x += 1*speed*dt;
		}
	if(Keyboard::isKeyPressed(Keyboard::W) && position.y > GAME_WINDOW.top + this->getBorders().height * 0.5)
		{
			position.y -= 1*speed*dt;
		}
	if(Keyboard::isKeyPressed(Keyboard::S) && position.y < GAME_WINDOW.height -this->getBorders().height * 0.5)
	{
		position.y += 1*speed*dt;
	}
	if(Keyboard::isKeyPressed(Keyboard::Space))
	{
		if(shoot <= 0)
		{	
			BulletEngine::shoot(position, 30, damage, sprite.getRotation());
			shoot=shootSpeed;
		}
	}
	
	if(immunity > 0)
		immunity -= dt;

	shoot-=dt;
	sprite.setPosition(position);
		
	hitbox.top = sprite.getGlobalBounds().top + (sprite.getLocalBounds().height * scale);
	hitbox.left = sprite.getGlobalBounds().left + (sprite.getLocalBounds().width * scale);
	hitbox.height = sprite.getGlobalBounds().height - (sprite.getLocalBounds().height * scale * 2);
	hitbox.width = sprite.getGlobalBounds().width - (sprite.getLocalBounds().width * scale * 2);
	// asd
}

void Player::initialize(Vector2f position, float speed, IntRect sprite)
{
	this->position = position;
	this->speed = speed;

	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(-90);
	this->sprite.setPosition(this->position);
	dead=false;
	
	scale = 10; // prosenttia spriten koosta
	scale = 100-scale;
	scale *= 0.005;

	shoot = shootSpeed = 1.5;
	damage = 1;

	health = maxHealth = 5;
	immunity = _immunity = 5;

}

void Player::gotHit(float dmg)
{
	if(immunity <= 0)
	{
		health -= dmg;
		immunity = _immunity;
	}

	if(health <= 0)
	{
		kill();
		health = 0;
	}
}
void Player::spaceGlue(int action)
{
	switch (action){

	case 1: // recover health
		{
			if(health < maxHealth)
				health++;
			break;
		}
	case 2: // increase health
		{
			maxHealth++;
			if(health < maxHealth)
				health++;
			break;
		}
	case 3: // faster shooting
		{
			if(shootSpeed > 0.75)
				shootSpeed -= 0.3;
			break;
		}
	case 4: // faster movement
		{
			if(speed < 50)
				speed += 5;
			break;
		}
	}
}
float Player::getHealth()
{
	return health;
}

float Player::getMaxHealth()
{
	return maxHealth;
}