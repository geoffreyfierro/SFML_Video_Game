//
// Created by geoff on 6/10/2020.
//

#include "FinishFlag.h"

FinishFlag::FinishFlag() {
    if(!flagTexture.loadFromFile("GFGame/Pictures/Flag.png"))
        std::cout << "Could Not Load Flag Image" << std::endl;

    flag.setTexture(flagTexture);
    flag.setScale(4.f,4.f);
    flag.setPosition(6500,1545-flag.getGlobalBounds().height);
}

void FinishFlag::draw(sf::RenderWindow &window) {
    window.draw(flag);
}

float FinishFlag::getTopSide() {
    return flag.getGlobalBounds().top;
}

float FinishFlag::getHeight() {
    return flag.getGlobalBounds().height;
}

float FinishFlag::getLeftSide() {
    return flag.getGlobalBounds().left;
}

float FinishFlag::getWidth() {
    return flag.getGlobalBounds().width;
}
