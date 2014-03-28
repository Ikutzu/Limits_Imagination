#pragma once
#include <SFML\Graphics.hpp>

using namespace std;
using namespace sf;

class Scene
{
public:
	Scene(void);
	~Scene(void);
	
	virtual void update(float dt);
	virtual void draw(RenderWindow* window);
	
	void pause(bool pause);
	bool activated();

private:
	bool sceneActive;
	
};

