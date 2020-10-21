//
// Created by geoff on 5/27/2020.
//

#ifndef SFML_PROJECT_PLATFORM_H
#define SFML_PROJECT_PLATFORM_H

#include <SFML/Graphics.hpp>

class Platform {
private:
    sf::Sprite block;
    sf::Texture texture;

    float topSide, bottomSide, leftSide, rightSide;

public:
    Platform();
    Platform(float xPos, float yPos);
    void draw(sf::RenderWindow &window);
    float getTopSide();
    float getBottomSide();
    float getLeftSide();
    float getRightSide();
};


#endif //SFML_PROJECT_PLATFORM_H
