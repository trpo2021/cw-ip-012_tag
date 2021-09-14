#include <SFML/Graphics.hpp>
#include "menu.h"

using namespace sf;

int main()

{
	RenderWindow app(VideoMode(400,400), "15 puzzle");
	menu(app);
	
	while (app.isOpen())
	{
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}
		
		app.clear();

		app.display();
	}
	return 0;
}