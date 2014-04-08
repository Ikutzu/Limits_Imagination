#include "MenuButton.h"


MenuButton::~MenuButton(void)
{
}

void MenuButton::initialize(Vector2f pos, Texture *tex, IntRect _idle, IntRect _hover)
{
	idle = _idle;
	hover = _hover;

	sprite = Sprite();
	sprite.setTexture(*tex);
	sprite.setTextureRect(this->idle);
	sprite.setOrigin(idle.width*0.5,idle.height*0.5);
	sprite.setPosition(pos);
	selected = false;

}

bool MenuButton::update(float dt)
{
	if(selected)
	{
		cout << "asdasd" << endl;
		sprite.setTextureRect(hover);
		if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			return true;
		}
	}
	else if(!selected)
		sprite.setTextureRect(idle);
	
	return false;
}

void MenuButton::draw(RenderWindow* win)
{
	win->draw(sprite);
}

void MenuButton::setAction(_action action)
{
	iDO = action;
}

MenuButton::_action MenuButton::action()
{
	return iDO;
}

void MenuButton::setSelected(bool select)
{
	selected = select;
}

bool MenuButton::isSelected()
{
	return selected;
}