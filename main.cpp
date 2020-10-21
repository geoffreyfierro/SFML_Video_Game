#include <iostream>
#include <SFML/Graphics.hpp>
#include "GFGame/GFGame.h"

int main() {
    bool GAME_STARTED = true;
    sf::RenderWindow window(sf::VideoMode(1920,1080,32),"Snail Explorer");
    window.setFramerateLimit(60);
    GFGame game;

    game.start(window);

    while(window.isOpen()){


        sf::Event event;

        while(window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();

            }
            game.addEvents(window, event);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            GAME_STARTED = false;
            game.exit();
        }

        window.clear(sf::Color::Black);

        if(GAME_STARTED) {
            game.addEvents(window);
            window.draw(game);
            //window.draw(game.getThumbnail());
            //window.draw(game.getInfo(window));
        }

        window.display();
    }
    return 0;
}