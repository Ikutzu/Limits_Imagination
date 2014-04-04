#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	GameObject(Vector2f position, Texture* tex, IntRect sprite);
	~GameObject(void);

	void virtual update(float dt);
	void const draw(RenderWindow* window);
	void kill();
	bool isDead();
	float getSpeed();
	float getRotation();
	Vector2f getPosition();
	FloatRect getBorders();

protected:
	Texture* tex;
	Vector2f position;
	Sprite sprite;

	float speed;
	bool dead;
};

