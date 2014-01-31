#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
class GameObject
{
public:
	//float x, float y, float speed, sf::Texture tex, sf::IntRect sprite
	GameObject(sf::Vector2f position, float speed, sf::Texture* tex, sf::IntRect sprite);
	~GameObject(void);

	sf::Vector2f getPosition();
	virtual void Update(float dt);
	void draw(sf::RenderWindow* window);

protected:
	sf::Vector2f position;
	float speed;
	sf::Sprite sprite;
	sf::FloatRect borders;
};

