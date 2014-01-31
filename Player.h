#pragma once
#include "gameobject.h"
class Player :
	public GameObject
{
public:
	//Player(float x, float y, float speed, sf::Texture tex, sf::IntRect sprite);
	Player(sf::Vector2f position, float speed, sf::Texture *tex, sf::IntRect sprite);
	~Player(void);

	void Update(float dt);

private:
	
};

