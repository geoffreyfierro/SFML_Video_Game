//
// Created by geoff on 6/10/2020.
//

#ifndef SFML_PROJECT_WONGAMESCREEN_H
#define SFML_PROJECT_WONGAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class WonGameScreen {
private:
    sf::Text wonText;
    sf::Font gameFont;
    sf::RectangleShape background;

public:
    WonGameScreen();
    void draw(sf::RenderWindow &window, Player player);
};


#endif //SFML_PROJECT_WONGAMESCREEN_H
