#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletEngine.h"
#include "Globals.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;


int main()
{
    RenderWindow window(VideoMode(900, 720), "Limitus: Imaginatus");
	RenderWindow* win = &window;

	RectangleShape shape(Vector2f(300, 720));
	shape.setFillColor(Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	Sprite _background;
	Texture background;
	background.loadFromFile("background.png");
	_background.setTexture(background);

	
	texture.loadFromFile("alus.png");
	
	Clock clock;
	
	Player player(Vector2f(268,600), 40, IntRect(0,0,64,64));

	vector<BulletEngine*> bEngine;
	vector<BulletEngine*>::iterator bIt;
	
	vector<Enemy*> enemies;
	vector<Enemy*>::iterator eit;

	float shoot=0;

	float enemySpawnTimer=0;
	
	while (window.isOpen())
    {
		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }


		if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			if(shoot <= 0)
			{
				BulletEngine *engine1 = new BulletEngine(20);
				bEngine.push_back(engine1);
				shoot=1;
			}
		}

		if(enemySpawnTimer <= 0)
		{
			Enemy *enemy = new Enemy(Vector2f(100,100), 30, IntRect(0,0,64,64));
			enemies.push_back(enemy);
			enemySpawnTimer = 50;
			cout << "Enemy Spawns!!" << endl;
		}

		Time elapsed = clock.getElapsedTime();
		float dt = 0.00001f*elapsed.asMicroseconds();
		clock.restart();
		shoot-=dt;
		enemySpawnTimer-=dt;
		for(bIt = bEngine.begin(); bIt != bEngine.end();)
		{
			(*bIt)->update(dt);
			if (!(*bIt)->isEmpty)
			{
				bIt++;
			}
			else
			{
				(*bIt)->~BulletEngine();
				bIt = bEngine.erase(bIt);
			}
		}
		bEngine.shrink_to_fit();

		for(eit=enemies.begin(); eit != enemies.end(); eit++)
		{
			(*eit)->update(dt,0);
		}
		player.update(dt);
		
		//cout << dt*0.1 << endl;

        window.clear();
		
		window.draw(_background);
		
		player.draw(win);
		for(bIt = bEngine.begin(); bIt != bEngine.end(); bIt++)
		{
			(*bIt)->draw(win);
		}
		for(eit=enemies.begin(); eit != enemies.end(); eit++)
		{
			(*eit)->draw(win);
		}
		window.draw(shape);
        window.display();
    }

    return 0;
}