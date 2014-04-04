#include "GameObject.h"
#include "Globals.h"

GameObject::GameObject()
{}

GameObject::GameObject(Vector2f position, Texture* tex, IntRect sprite)
{
	this->position = position;
	speed = 0;
	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	dead=false;
}

GameObject::~GameObject(void)
{
}

Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::update(float dt)
{
}

bool GameObject::isDead()
{
	return dead;
}

void const GameObject::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

FloatRect GameObject::getBorders()
{
	return sprite.getGlobalBounds();
}

void GameObject::kill()
{
	dead = true;
}

float GameObject::getRotation()
{
	return sprite.getRotation();
}

float GameObject::getSpeed()
{
	return speed;
}