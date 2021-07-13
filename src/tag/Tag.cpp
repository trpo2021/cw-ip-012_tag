#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;


int main()

{
	RenderWindow window(VideoMode(800,600), "15 puzzle");

	
	
	menu(window);
	
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		window.clear();

		window.display();
	}
	return 0;
}