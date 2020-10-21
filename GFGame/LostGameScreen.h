//
// Created by geoff on 6/10/2020.
//

#ifndef SFML_PROJECT_LOSTGAMESCREEN_H
#define SFML_PROJECT_LOSTGAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class LostGameScreen {
private:
    sf::Text lostText;
    sf::Font gameFont;
    sf::RectangleShape background;

public:
    LostGameScreen();
    void draw(sf::RenderWindow &window, Player player);
};


#endif //SFML_PROJECT_LOSTGAMESCREEN_H
