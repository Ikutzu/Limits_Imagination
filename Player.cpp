#include "Player.h"
#include "Globals.h"

Player::Player(Vector2f position, float speed, Texture *tex, IntRect sprite) : GameObject(position, speed, tex, sprite)
{
}

Player::~Player(void)
{
}

void Player::update(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::A) && position.x > GAME_WINDOW.left)
		{
			position.x -= 1*speed*dt;
			cout << "A is down" << endl;
		}
	if(Keyboard::isKeyPressed(Keyboard::D) && position.x < GAME_WINDOW.width-borders.width)
		{
			position.x += 1*speed*dt;
			cout << "D is down" << endl;
		}
		if(Keyboard::isKeyPressed(Keyboard::W) && position.y > GAME_WINDOW.top)
		{
			position.y -= 1*speed*dt;
			cout << "W is down" << endl;
		}
		if(Keyboard::isKeyPressed(Keyboard::S) && position.y < GAME_WINDOW.height -borders.height)
		{
			position.y += 1*speed*dt;
			cout << "S is down" << endl;
		}

		sprite.setPosition(position);
}
