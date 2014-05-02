#include "Shrapnell.h"
#include "Globals.h"


Shrapnell::Shrapnell(Vector2f position, float speed, float direction, IntRect sprite): GameObject(position, sprite)
{
	spin = rand()%10;
	spin -= 5;
	this->speed = speed;
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	this->sprite.setRotation(direction);
	angle = direction;
	lifetime = 10;
}


Shrapnell::~Shrapnell(void)
{
}
void Shrapnell::update(float dt)
{
	if(lifetime <= 0)
		kill();
	else
	{
		lifetime-=dt;
		sprite.setRotation(sprite.getRotation()+spin*dt);
		position.x += speed*dt*cos(angle*degree);
		position.y += speed*dt*sin(angle*degree);
	
		sprite.setPosition(position);

		if (position.x < GAME_WINDOW.left-16 || position.x > GAME_WINDOW.width+16 ||
			position.y < GAME_WINDOW.top-16  || position.y > GAME_WINDOW.height+16)
			dead = true;
	}
}