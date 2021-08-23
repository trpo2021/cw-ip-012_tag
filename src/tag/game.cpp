
#include <SFML/Graphics.hpp>


using namespace sf;

void game(RenderWindow& app) {
    app.setFramerateLimit(60);
    Texture Texture;
    int u = rand()% 3 + 1;
    switch (u)
    {
    case 1:
        Texture.loadFromFile("images/6.png");
        break;
    case 2:
        Texture.loadFromFile("images/5.png");
        break;
    case 3:
        Texture.loadFromFile("images/4.png");
        break;
    }
    
    Sprite s[17];
   
    int side = 100;
    int mass[6][6] = { 0 };
    int q = 0;
    int i,j;
    
    for(i = 0; i < 4; i++)
        for (j = 0; j < 4; j++) {
            q++;
            s[q].setTexture(Texture);
            s[q].setTextureRect(IntRect(i * side, j * side, side, side));
            mass[i + 1][j + 1] = q;
        }
    while (app.isOpen())
    {
        Event event;
        while (app.pollEvent(event))
        {
            if (event.type == Event::Closed)
                app.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))
                app.close();

            if (event.type == Event::MouseButtonPressed)
                if (event.key.code == Mouse::Left) {

                    Vector2i pos = Mouse::getPosition(app);

                    int x = pos.x / side + 1;
                    int y = pos.y / side + 1;

                    int dx = 0;
                    int dy = 0;

                    int t;
                    if (u == 1 || u == 2)
                        t = 16;
                    else if (u != 1 && u != 2)
                        t = 7;

                    if (mass[x - 1][y] == t) {
                        dx = -1;
                        dy = 0;
                    }
                    if (mass[x + 1][y] == t) {
                        dx = 1;
                        dy = 0;
                    }
                    if (mass[x][y - 1] == t) {
                        dx = 0;
                        dy = -1;
                    }
                    if (mass[x][y + 1] == t) {
                        dx = 0;
                        dy = 1;
                    }

                    q = mass[x][y];
                    mass[x][y] = t;
                    mass[x + dx][y + dy] = q;

                    s[t].move(-dx * side, -dy * side);
                    float speed = 6;
                    for (int i = 0; i < side; i += speed) {
                        s[q].move(speed * dx, speed * dy);
                        app.draw(s[t]);
                        app.draw(s[q]);
                        app.display();
                    }
                }
        }

        app.clear(Color(230, 168, 215));
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                q = mass[i + 1][j + 1];
                s[q].setPosition(i*side, j*side);
                app.draw(s[q]);
            }
        
        app.display();

    }  
}