#include "GameObject.h"
#include <SFML\Graphics.hpp>

using namespace sf;

GameObject::GameObject(Vector2f position, float speed, Texture* tex, IntRect sprite)
{
	this->position = position;
	this->speed = speed;

	this->sprite.setTexture(*tex);
	this->sprite.setTextureRect(sprite);
	borders = this->sprite.getGlobalBounds();
}


GameObject::~GameObject(void)
{
}


Vector2f GameObject::getPosition()
{
	return position;
}

void GameObject::Update(float dt)
{
}

void GameObject::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}