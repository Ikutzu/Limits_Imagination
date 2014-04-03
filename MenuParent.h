#pragma once
#include "scene.h"



class MenuParent :
	public Scene
{
public:
	MenuParent(void);
	~MenuParent(void);

	void update(float dt);
	void draw(RenderWindow* window);

private:


};

