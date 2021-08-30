#include <SFML/Graphics.hpp>
#include "game.h"
#include "../game.cpp"

using namespace sf;

void menu(RenderWindow& app) {
	Texture Texture1, Texture2, Texture3;
	Texture1.loadFromFile("images/1.png");
	Texture2.loadFromFile("images/2.png");


	Sprite menu1(Texture1), menu2(Texture2);

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(125, 150);
	menu2.setPosition(125, 210);


	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		app.clear(Color(230, 168, 215));
		if (IntRect(125, 150, 400, 50).contains(Mouse::getPosition(app))) {
			menu1.setColor(Color::Magenta); menuNum = 1;
		}
		else if (IntRect(125, 210, 400, 50).contains(Mouse::getPosition(app))) {
			menu2.setColor(Color::Magenta); menuNum = 2;
		}
		Event event;
		while (app.pollEvent(event)) {

			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					if (menuNum == 1) {
						isMenu = false;
						game(app);
					}
					if (menuNum == 2) {
						app.close();
						isMenu = false;
					}
				}
			}
		}

		app.draw(menu1);
		app.draw(menu2);

		app.display();
	}
}