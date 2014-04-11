#include "Mainmenu.h"

Mainmenu::Mainmenu(void)
{
	background.loadFromFile("menubackground.png");
	_background.setTexture(background);

	texture.loadFromFile("menu.png");
	tex = &texture;

	start.initialize(Vector2f(300, 360), tex, IntRect(0,0,128,64), IntRect(128,0, 128, 64));
	start.setAction(MenuButton::_action::START);
	start.setSelected(true);

	quit.initialize(Vector2f(300, 450), tex, IntRect(0,64,128, 64), IntRect(128,64,128,64));
	quit.setAction(MenuButton::_action::QUIT);

	MenuButton* pointer = &start;
	buttonList.push_back(pointer);
	pointer = &quit;
	buttonList.push_back(pointer);
	current = buttonList.begin();
	holdTimer = 0;
}

Mainmenu::~Mainmenu(void)
{
}

void Mainmenu::update(float dt)
{
	switchButton();
	
	if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::S))
		holdTimer += dt;
	if( !Keyboard::isKeyPressed(Keyboard::W) && 
		!Keyboard::isKeyPressed(Keyboard::S) )
		holdTimer = 5;

		for(it = buttonList.begin(); it != buttonList.end();it++)
		{
			if((*it)->update(dt))
			{
				buttonPress((*it)->action());
				break;
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape))
			SceneSystem::closeScene();
	
}

void Mainmenu::draw(RenderWindow* window)
{
	window->draw(_background);
	for(it = buttonList.begin(); it != buttonList.end();it++)
		(*it)->draw(window);
}

void Mainmenu::buttonPress(MenuButton::_action action)
{
	switch (action)
	{
		case MenuButton::_action::START:
			{
				Game* game = new Game;
				SceneSystem::changeScene(game);
				break;
			}
		case MenuButton::_action::QUIT:
			{
				SceneSystem::closeScene();
				break;
			}
	}
}

void Mainmenu::switchButton()
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