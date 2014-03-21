#pragma once
#include "Scene.h"
class Mainmenu :
	public Scene
{
public:
	Mainmenu(void);
	~Mainmenu(void);
		
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
};

