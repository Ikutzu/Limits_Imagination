#pragma once
#include "Game.h"
#include "Scene.h"

#include <SFML\Graphics.hpp>

using namespace sf;

class Mainmenu :
	public Scene
{
public:
	Mainmenu(void);
	~Mainmenu(void);
		
	void update(float dt);
	void draw(RenderWindow* window);
};

