#include "GameObject.h"
#include "Globals.h"

Texture* GameObject::tex;

GameObject::GameObject()
{}

GameObject::GameObject(Vector2f position, IntRect sprite)
{
	this->position = position;
	speed = 0;
	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setPosition(this->position);
	dead=false;
}

GameObject::~GameObject(void)
{
}

void GameObject::setTexture(Texture* texture)
{
	tex = texture;
}

void GameObject::changeSpriteRect(IntRect newSprite)
{
	sprite.setTextureRect(newSprite);
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