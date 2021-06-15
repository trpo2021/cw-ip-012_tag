
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(256, 256), "15-Puzzle!");
    window.setFramerateLimit(60);

    Texture texture;
    texture.loadFromFile("images/15.png");

    int Widhtblock = 64;

    int grid[6][6] = {0};

    Sprite sprite[17];

    int n = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            n++;
            sprite[n].setTexture(texture);
            sprite[n].setTextureRect(IntRect(
                    i * Widhtblock, j * Widhtblock, Widhtblock, Widhtblock));
            grid[i + 1][j + 1] = n;
        }

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)

                window.close();

            if (event.type == Event::MouseButtonPressed) {
                if (event.key.code == Mouse::Left) {
                    Vector2i position = Mouse::getPosition(window);

                    int x = position.x / Widhtblock + 1;
                    int y = position.y / Widhtblock + 1;

                    int dx = 0;
                    int dy = 0;

                    if (grid[x + 1][y] == 16) {
                        dx = 1;
                        dy = 0;
                    };

                    if (grid[x][y + 1] == 16) {
                        dx = 0;
                        dy = 1;
                    };

                    if (grid[x][y - 1] == 16) {
                        dx = 0;
                        dy = -1;
                    };

                    if (grid[x - 1][y] == 16) {
                        dx = -1;
                        dy = 0;
                    };

                    int temp = grid[x][y];
                    grid[x][y] = 16;
                    grid[x + dx][y + dy] = temp;

                    sprite[16].move(-dx * Widhtblock, -dy * Widhtblock);

                    float speed = 6;
                    for (int i = 0; i < Widhtblock; i += speed) {
                        sprite[temp].move(speed * dx, speed * dy);

                        window.draw(sprite[16]);

                        window.draw(sprite[temp]);

                        window.display();
                    }
                }
            }
        }

        window.clear(Color::White);

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                int n = grid[i + 1][j + 1];
                sprite[n].setPosition(i * Widhtblock, j * Widhtblock);
                window.draw(sprite[n]);
            }

        window.display();
    }

    return 0;
}

