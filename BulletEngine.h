#pragma once
#include "Bullet.h"
#include "Shrapnell.h"

#include <vector>
#include <SFML\System.hpp>

using namespace std;
using namespace sf;

class BulletEngine
{
public:

	static void update(float dt);
	static void draw(RenderWindow* window);
	static void shoot(Vector2f pos, float speed, float damage, float angle, int ammount);
	static void shoot(Vector2f pos, float speed, float damage, float angle);
	static void shrapnell(Vector2f pos, float speed, float angle, int ammount, IntRect sprite);
	static void clear();

	static vector<Bullet*> bulletL;
	static vector<Shrapnell*> shrapnellL;

private:
		
	static vector<Bullet*>::iterator bit;
	static vector<Shrapnell*>::iterator shit;
	static vector<float> angles;
	static vector<float>::iterator ait;
	static float angle;

};

