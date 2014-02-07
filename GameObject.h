#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	//float x, float y, float speed, sf::Texture tex, sf::IntRect sprite
	GameObject(Vector2f position, float speed, IntRect sprite);
	~GameObject(void);

	Vector2f getPosition();
	void virtual update(float dt);
	void const draw(RenderWindow* window);
	bool isDead();

protected:
	Vector2f position;
	float speed;
	Sprite sprite;
	FloatRect borders;
	bool dead;
	
};

