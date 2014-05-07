#include "Pausemenu.h"


Pausemenu::Pausemenu(void)
{
	texture.loadFromFile("menu.png");
	tex = &texture;

	quit.initialize(Vector2f(740, 450), tex, IntRect(0,128,256, 96), IntRect(0,128,256,96));
	quit.setAction(MenuButton::_action::QUIT);
	quit.setSelected(true);

	MenuButton* pointer = &quit;
	buttonList.push_back(pointer);
	current = buttonList.begin();
	holdTimer = 0;
}

Pausemenu::~Pausemenu(void)
{
}

void Pausemenu::update(float dt)
{
	switchButton();
	
	if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S))
		holdTimer += dt;
	if(	!Keyboard::isKeyPressed(Keyboard::W) && 
		!Keyboard::isKeyPressed(Keyboard::S))
		holdTimer = 5;

	for(it = buttonList.begin(); it != buttonList.end();it++)
	{
		if((*it)->update(dt))
		{
			buttonPress((*it)->action());
			break;
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape) )
		SceneSystem::MainMenu();
	
}

void Pausemenu::draw(RenderWindow* window)
{
	for(it = buttonList.begin(); it != buttonList.end();it++)
		(*it)->draw(window);
}

void Pausemenu::buttonPress(MenuButton::_action action)
{
	switch (action)
	{
		case MenuButton::_action::START:
			{
				SceneSystem::changeScene(new Game);
				break;
			}
		case MenuButton::_action::QUIT:
			{
				SceneSystem::closeScene();
				break;
			}
	}
}

void Pausemenu::switchButton()
{
	if(Keyboard::isKeyPressed(Keyboard::W) && holdTimer >= 5)
	{
		holdTimer = 0;
		(*current)->setSelected(false);
		
		if(current == buttonList.begin())
			current = buttonList.end();
		
		current--;
				
		(*current)->setSelected(true);
	}
	if(Keyboard::isKeyPressed(Keyboard::S) && holdTimer >= 5)
	{
		holdTimer = 0;
		(*current)->setSelected(false);
		current++;
		if(current == buttonList.end())
		{
			current = buttonList.begin();
		}
		(*current)->setSelected(true);
	}
}