#pragma once

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

using namespace sf;

class GameObject
{
public:
	GameObject();
	GameObject(Vector2f position, IntRect sprite);
	~GameObject(void);

	static void setTexture(Texture* texture);
	void changeSpriteRect(IntRect newSprite);
	void virtual update(float dt);
	void const draw(RenderWindow* window);
	void kill();
	bool isDead();
	float getSpeed();
	float getRotation();
	Vector2f getPosition();
	FloatRect getBorders();
	

protected:
	static Texture* tex;
	Vector2f position;
	Sprite sprite;

	float speed;
	bool dead;
};

