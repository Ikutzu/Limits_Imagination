#pragma once
#include "Bullet.h"

#include <vector>
#include <SFML\System.hpp>

using namespace std;
using namespace sf;

class BulletEngine
{
public:
	BulletEngine();
	BulletEngine(Vector2f pos, Texture *tex, int ammount);
	BulletEngine(Vector2f pos, float angle, Texture *tex, int ammount);
	~BulletEngine(void);

	void update(float dt);
	void draw(RenderWindow* window);
	void shoot(Texture *tex, int ammount);
	bool isEmpty;

private:
	
	Vector2f position;
	vector<Bullet*> bulletL;
	vector<Bullet*>::iterator bit;
	vector<float> angles;
	vector<float>::iterator ait;
	float angle;

};

