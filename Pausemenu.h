#pragma once
#include "SFML\Graphics.hpp"
#include "scene.h"



class Pausemenu :
	public Scene
{
public:
	Pausemenu(void);
	~Pausemenu(void);

	void update(float dt);
	void draw(RenderWindow* window);

private:

	Sprite sprite;

};

