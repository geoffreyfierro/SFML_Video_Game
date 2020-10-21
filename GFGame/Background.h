//
// Created by geoff on 5/28/2020.
//

#ifndef SFML_PROJECT_BACKGROUND_H
#define SFML_PROJECT_BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background {
private:
    sf::Texture backgroundImage;
    sf::Sprite background;

public:
    Background();
    void setBackgorund(sf::RenderWindow &window);
};


#endif //SFML_PROJECT_BACKGROUND_H
