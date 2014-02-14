#include "Game.h"


int main()
{
    RenderWindow window(VideoMode(900, 720), "Limitus: Imaginatus");
	RenderWindow* win = &window;
	
	Sprite _background;
	Texture background;
	background.loadFromFile("background.png");
	_background.setTexture(background);

	Game game;
	
	Clock clock;
	


	while (window.isOpen())
    {
		Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

		Time elapsed = clock.getElapsedTime();
		float dt = 0.00001f*elapsed.asMicroseconds();
		clock.restart();
		
		
		game.update(dt);

        window.clear();
		window.draw(_background);
		game.draw(win);
		
		cout << dt*0.1 << endl;
	}

    return 0;
}