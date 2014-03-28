#pragma once
#include "Bullet.h"

#include <vector>
#include <SFML\System.hpp>

using namespace std;
using namespace sf;

class BulletEngine
{
public:

	static void update(float dt);
	static void draw(RenderWindow* window);
	static void shoot(Vector2f pos, float speed, float angle, Texture *tex, int ammount);
	static void shoot(Vector2f pos, float speed, float angle, Texture *tex);
	
	static vector<Bullet*> bulletL;

private:
		
	static vector<Bullet*>::iterator bit;
	static vector<float> angles;
	static vector<float>::iterator ait;
	static float angle;

};

