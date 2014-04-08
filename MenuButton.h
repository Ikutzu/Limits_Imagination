#pragma once

#include <string>
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class MenuButton
{
public:
	~MenuButton();
	
	enum _action	{	
						START,
						QUIT
					};

	void initialize(Vector2f pos, Texture *tex, IntRect _idle, IntRect _hover);

	bool update(float dt);
	void draw(RenderWindow* win);

	void setAction(_action action);
	_action action();
	
	void setSelected(bool select); 
	bool isSelected();

private:
	Sprite sprite;
	IntRect idle, hover;
	_action iDO;

	bool selected;
};