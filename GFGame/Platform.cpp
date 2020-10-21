//
// Created by geoff on 5/27/2020.
//

#include <iostream>
#include "Platform.h"

Platform::Platform() {
    if(!texture.loadFromFile("GFGame/Pictures/CustomGrass1.png"))
        std::cout << "Failed to Load Grass Image" << std::endl;

    block.setTexture(texture);
    block.setPosition(0,0);
    block.setScale(3.f,3.f);

    leftSide = block.getGlobalBounds().left;
    rightSide = leftSide + block.getGlobalBounds().width;
    topSide = block.getGlobalBounds().top;
    bottomSide = topSide + block.getGlobalBounds().height;

}

Platform::Platform(float xPos, float yPos) {
    if(!texture.loadFromFile("GFGame/Pictures/CustomGrass1.png"))
        std::cout << "Failed to Load Grass Image" << std::endl;

    block.setTexture(texture);
    block.setPosition(xPos,yPos);
    block.setScale(3.f,3.f);

    leftSide = block.getGlobalBounds().left;
    rightSide = leftSide + block.getGlobalBounds().width;
    topSide = block.getGlobalBounds().top;
    bottomSide = topSide + block.getGlobalBounds().height;
}

void Platform::draw(sf::RenderWindow &window) {
    window.draw(block);
}

float Platform::getTopSide() {
    return topSide;
}

float Platform::getBottomSide() {
    return bottomSide;
}

float Platform::getLeftSide() {
    return leftSide;
}

float Platform::getRightSide() {
    return rightSide;
}


