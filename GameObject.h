#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	GameObject(Vector2f position, float speed, Texture* tex, IntRect sprite);
	~GameObject(void);

	Vector2f getPosition();
	void virtual update(float dt);
	void const draw(RenderWindow* window);
	FloatRect getBorders();
	bool isDead();

protected:
	Texture* tex;
	Vector2f position;
	float speed;
	Sprite sprite;
	FloatRect borders;
	bool dead;
};

