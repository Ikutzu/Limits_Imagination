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
	~BulletEngine(void);

	void update(float dt);
	void draw(RenderWindow* window);
	void shoot(Vector2f pos, float speed, float angle, Texture *tex, int ammount);
	void shoot(Vector2f pos, float speed, float angle, Texture *tex);
	
	vector<Bullet*> bulletL;

private:
	
	Vector2f position;
	
	vector<Bullet*>::iterator bit;
	vector<float> angles;
	vector<float>::iterator ait;
	float angle;

};

