//
// Created by geoff on 5/28/2020.
//

#include <iostream>
#include "Background.h"

void Background::setBackgorund(sf::RenderWindow &window) {
    window.draw(background);
}

Background::Background() {
    if(!backgroundImage.loadFromFile("GFGame/Pictures/Background.png"))
        std::cout << "Could not load Backgorund.png" << std::endl;

    background.setTexture(backgroundImage);
    background.setPosition(0,0);
}
