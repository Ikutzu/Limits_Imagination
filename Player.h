#pragma once
#include "GameObject.h"
#include "BulletEngine.h"

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player :
	public GameObject
{
public:
	Player();
	// Player(Vector2f position, float speed, Texture *tex, IntRect sprite);
	~Player(void);

	void update(float dt);
	void initialize(Vector2f position, float speed, Texture* tex, IntRect sprite);
	
	FloatRect hitbox;
private:
	float scale;
	float shoot;
};

