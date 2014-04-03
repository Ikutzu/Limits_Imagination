#include "Mainmenu.h"

RectangleShape bjuton(Vector2f(128, 512));

Mainmenu::Mainmenu(void)
{
	bjuton.setFillColor(Color::Blue);
	bjuton.setPosition(0,0);
}

Mainmenu::~Mainmenu(void)
{
}

void Mainmenu::update(float dt)
{
	if(Keyboard::isKeyPressed(Keyboard::Escape))
		SceneSystem::closeScene();

	if(Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Space))
	{
		Game* game = new Game;
		SceneSystem::changeScene(game);
	}
	
}

void Mainmenu::draw(RenderWindow* window)
{
	window->draw(bjuton);
}