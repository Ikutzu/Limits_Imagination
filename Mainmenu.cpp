#include "Mainmenu.h"

Mainmenu::Mainmenu(void)
{
	background.loadFromFile("menubackground.png");
	_background.setTexture(background);

	texture.loadFromFile("menu.png");
	tex = &texture;
	start.initialize(Vector2f(300, 360), tex, IntRect(0,0,256,64), IntRect(0,65, 256, 64));
	start.setAction(MenuButton::_action::START);
	quit.initialize(Vector2f(300, 450), tex, IntRect(0,64, 256, 64), IntRect(0,0,256,64));
	quit.setAction(MenuButton::_action::QUIT);
	MenuButton* pointer = &start;
	buttonList.push_back(pointer);
	pointer = &quit;
	buttonList.push_back(pointer);
	current = buttonList.begin();
}

Mainmenu::~Mainmenu(void)
{
}

void Mainmenu::update(float dt)
{
	switchButton();
	for(it = buttonList.begin(); it != buttonList.end();it++)
	{
		if((*it)->update(dt))
		{
			buttonPress();
			break;
		}
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape))
		SceneSystem::closeScene();

	//if(Keyboard::isKeyPressed(Keyboard::Space))//Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space)
}

void Mainmenu::draw(RenderWindow* window)
{
	for(it = buttonList.begin(); it != buttonList.end();it++)
		(*it)->draw(window);
}

void Mainmenu::buttonPress()
{
	MenuButton::_action action = MenuButton::_action::START;
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
	if(Keyboard::isKeyPressed(Keyboard::W))
	{
		(*current)->setSelected(false);
		if(current == buttonList.begin())
		{
			current = buttonList.end();
			current--;
		}
		(*current)->setSelected(true);
	}
	if(Keyboard::isKeyPressed(Keyboard::S))
	{
		(*current)->setSelected(false);
		current++;
		if(current == buttonList.end())
		{
			current = buttonList.begin();
		}
		(*current)->setSelected(true);
	}
}