#pragma once
#include "Bullet.h"

#include <vector>

using namespace std;
using namespace sf;

class BulletEngine
{
public:
	BulletEngine();
	BulletEngine(Texture *tex, int ammount);
	~BulletEngine(void);

	void update(float dt);
	void draw(RenderWindow* window);
	void shoot(Texture *tex, int ammount);
	bool isEmpty;

private:
	
	vector<Bullet*> bulletL;
	vector<Bullet*>::iterator bit;
	vector<float> angles;
	vector<float>::iterator ait;
	float angle;

};

