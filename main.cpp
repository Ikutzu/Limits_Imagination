#include "Player.h"
#include "Bullet.h"
#include "BulletEngine.h"

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

	Texture texture;
	Texture* tex = &texture;
	texture.loadFromFile("alus.png");
    
	Clock clock;
	
	Player player(Vector2f(268,600), 40, tex, IntRect(0,0,64,64));

	vector<BulletEngine*> bEngine;
	vector<BulletEngine*>::iterator bIt;

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
			BulletEngine *engine1 = new BulletEngine(tex, 40);
			bEngine.push_back(engine1);
		}
		Time elapsed = clock.getElapsedTime();
		float dt = 0.00001f*elapsed.asMicroseconds();
		clock.restart();

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
		player.update(dt);

		cout << dt << endl;

        window.clear();
		
		window.draw(_background);
		
		player.draw(win);
		for(bIt = bEngine.begin(); bIt != bEngine.end(); bIt++)
		{
			(*bIt)->draw(win);
		}
		window.draw(shape);
        window.display();
    }

    return 0;
}