//
// Created by geoff on 6/10/2020.
//

#ifndef SFML_PROJECT_FINISHFLAG_H
#define SFML_PROJECT_FINISHFLAG_H

#include <SFML/Graphics.hpp>
#include <iostream>


class FinishFlag {
private:
    sf::Sprite flag;
    sf::Texture flagTexture;

public:
    FinishFlag();
    void draw(sf::RenderWindow &window);
    float getTopSide();
    float getHeight();
    float getLeftSide();
    float getWidth();

};


#endif //SFML_PROJECT_FINISHFLAG_H
