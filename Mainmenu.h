#pragma once
#include "Game.h"
#include "Scene.h"
#include "MenuButton.h"

#include <SFML\Graphics.hpp>
#include <vector>

using namespace sf;

class Mainmenu :
	public Scene
{
public:
	Mainmenu(void);
	~Mainmenu(void);
		
	void update(float dt);
	void draw(RenderWindow* window);

	void buttonPress(MenuButton::_action action);
	void switchButton();

private:
	
	float holdTimer;

	Sprite _background;
	Texture background;

	Texture texture;
	Texture* tex;

	MenuButton start;
	MenuButton quit;

	vector<MenuButton*> buttonList;
	vector<MenuButton*>::iterator it;
	vector<MenuButton*>::iterator current;
};

