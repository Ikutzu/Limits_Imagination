#include "Player.h"

Player::Player(Vector2f position, float speed, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
}

Player::~Player(void)
{
}

void Player::update(float dt)
{
		if(Keyboard::isKeyPressed(Keyboard::A) && position.x > 0)
		{
			position.x -= 1*speed*dt;
			cout << "A is down" << endl;
		}
		if(Keyboard::isKeyPressed(Keyboard::D) && position.x < 600-borders.width)
		{
			position.x += 1*speed*dt;
			cout << "D is down" << endl;
		}
		if(Keyboard::isKeyPressed(Keyboard::W) && position.y > 0)
		{
			position.y -= 1*speed*dt;
			cout << "W is down" << endl;
		}
		if(Keyboard::isKeyPressed(Keyboard::S) && position.y < 720 -borders.height)
		{
			position.y += 1*speed*dt;
			cout << "S is down" << endl;
		}

		sprite.setPosition(position);
}
