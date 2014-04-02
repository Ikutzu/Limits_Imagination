#include "Game.h"
#include "Mainmenu.h"


void main()
{
    RenderWindow window(VideoMode(900, 720), "Limitus: Imaginatus");
	RenderWindow* win = &window;
//	window.setFramerateLimit(60);
	

	SceneSystem::openScene(new Mainmenu);
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
		
		
		SceneSystem::update(dt);

        window.clear();
		SceneSystem::draw(win);
		window.display();
		cout << elapsed.asSeconds() << endl;
		 
		//system("cls");
	}
}