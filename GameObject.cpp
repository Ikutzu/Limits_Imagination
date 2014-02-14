#include "GameObject.h"

GameObject::GameObject()
{}

GameObject::GameObject(Vector2f position, float speed, Texture* tex, IntRect sprite)
{
	this->position = position;
	this->speed = speed;

	this->tex = tex;
	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	this->sprite.setOrigin(sprite.width/2, sprite.height/2);
	borders = this->sprite.getGlobalBounds();
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
	return borders;
}
