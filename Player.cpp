#include "Player.h"
#include "Bullet.h"

#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
/*
Player::Player(float x, float y, float speed, sf::Texture tex, sf::IntRect sprite) : GameObject(x, y, speed, tex, sprite)
{
}*/
Player::Player(sf::Vector2f position, float speed, sf::Texture *tex, sf::IntRect sprite) : GameObject(position, speed, tex, sprite)
{
}

Player::~Player(void)
{
}

void Player::Update(float dt)
{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && position.x > 0)
		{
			position.x -= 1*speed*dt;
			cout << "A is down" << endl;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && position.x < 600-borders.width)
		{
			position.x += 1*speed*dt;
			cout << "D is down" << endl;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && position.y > 0)
		{
			position.y -= 1*speed*dt;
			cout << "W is down" << endl;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && position.y < 720 -borders.height)
		{
			position.y += 1*speed*dt;
			cout << "S is down" << endl;
		}

		sprite.setPosition(position);
}

