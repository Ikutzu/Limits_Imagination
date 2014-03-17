#include "Player.h"
#include "Globals.h"

Player::Player()
{}
/*
Player::Player(Vector2f position, float speed, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
}
*/
Player::~Player(void)
{
}

void Player::update(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::A) && position.x > GAME_WINDOW.left+this->getBorders().width * 0.5)
		{
			position.x -= 1*speed*dt;
			cout << "A is down" << endl;
		}
	if(Keyboard::isKeyPressed(Keyboard::D) && position.x < GAME_WINDOW.width-this->getBorders().width * 0.5)
		{
			position.x += 1*speed*dt;
			cout << "D is down" << endl;
		}
	if(Keyboard::isKeyPressed(Keyboard::W) && position.y > GAME_WINDOW.top + this->getBorders().height * 0.5)
		{
			position.y -= 1*speed*dt;
			cout << "W is down" << endl;
		}
	if(Keyboard::isKeyPressed(Keyboard::S) && position.y < GAME_WINDOW.height -this->getBorders().height * 0.5)
	{
		position.y += 1*speed*dt;
		cout << "S is down" << endl;
	}

	sprite.setPosition(position);
		
	hitbox.top = sprite.getGlobalBounds().top + (sprite.getLocalBounds().height * scale);
	hitbox.left = sprite.getGlobalBounds().left + (sprite.getLocalBounds().width * scale);
	hitbox.height = sprite.getGlobalBounds().height - (sprite.getLocalBounds().height * scale * 2);
	hitbox.width = sprite.getGlobalBounds().width - (sprite.getLocalBounds().width * scale * 2);
	// asd
}

void Player::initialize(Vector2f position, float speed, Texture* tex, IntRect sprite)
{
	this->position = position;
	this->speed = speed;

	this->tex = tex;
	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(-90);
	dead=false;
	
	scale = 25; // prosenttia spriten koosta
	scale = 100-scale;
	scale *= 0.005;
}