#include <SFML/Graphics.hpp>

using namespace sf;

void menu(RenderWindow& window) {
	Texture Texture1, Texture2, Texture3;
	Texture1.loadFromFile("images/1.png");
	Texture2.loadFromFile("images/2.png");
	Texture3.loadFromFile("images/3.png");

	Sprite menu1(Texture1), menu2(Texture2), menu3(Texture3);

	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(325, 250);
	menu2.setPosition(325, 310);
	menu3.setPosition(325, 30);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(230, 168, 215));
		if (IntRect(325, 250, 600, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Magenta); menuNum = 1; }
		else if (IntRect(325, 310, 600, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Magenta); menuNum = 2; }
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::MouseButtonPressed) {
				if (event.key.code == Mouse::Left) {
					if (menuNum == 1) {
						isMenu = false;
					}
					if (menuNum == 2) {
						window.close();
						isMenu = false;
					}
				}
			}
		}

		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
}