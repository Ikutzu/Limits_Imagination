#pragma once
#include "SceneSystem.h"
#include "Game.h"
#include "SFML\Graphics.hpp"
#include "MenuButton.h"
#include "scene.h"



class Pausemenu :	public Scene
{
public:
	Pausemenu(void);
	~Pausemenu(void);
		
	void update(float dt);
	void draw(RenderWindow* window);

	void buttonPress(MenuButton::_action action);
	void switchButton();

private:
	
	float holdTimer;

	Texture texture;
	Texture* tex;

	MenuButton start;
	MenuButton quit;

	vector<MenuButton*> buttonList;
	vector<MenuButton*>::iterator it;
	vector<MenuButton*>::iterator current;
};