#pragma once
#include "GameObject.h"
#include "Bullet.h"

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Player :
	public GameObject
{
public:
	Player(Vector2f position, float speed, IntRect sprite);
	~Player(void);

	void update(float dt);

private:
	
};

