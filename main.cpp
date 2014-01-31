#include "Player.h"
#include "Bullet.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 720), "Limitus: Imaginatus");
	sf::RenderWindow* win = &window;

	sf::RectangleShape shape(sf::Vector2f(300, 720));
	shape.setFillColor(sf::Color::Color(100,40,40,255));
	shape.setPosition(600,0);
	
	sf::Sprite _background;
	sf::Texture background;
	background.loadFromFile("background.png");
	_background.setTexture(background);

	sf::Texture texture;
	sf::Texture* tex = &texture;
	texture.loadFromFile("alus.png");
    
	sf::Clock clock;
	
	Player player(sf::Vector2f(268,600), 40, tex, sf::IntRect(0,0,64,64));
	vector<Bullet> blist;
	vector<Bullet>::iterator it;

	while (window.isOpen())
    {
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mpos = sf::Mouse::getPosition();
			sf::Vector2f mpof;
			mpof.x = mpos.x;
			mpof.y = mpos.y;

			Bullet b1(mpof, 50, 0, tex, sf::IntRect(32,32,8,8));
			blist.push_back(b1);
		}
		sf::Time elapsed = clock.getElapsedTime();
		float dt = 0.00001f*elapsed.asMicroseconds();
		clock.restart();


		for(it = blist.begin(); it != blist.end(); it++)
		{
			it->Update(dt);
		}
		player.Update(dt);
		cout << dt << endl;

        window.clear();
		window.draw(shape);
		window.draw(_background);
		player.draw(win);
		for(it = blist.begin(); it != blist.end(); it++)
		{
			it->draw(win);
		}
        window.display();
    }

    return 0;
}