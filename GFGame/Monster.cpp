//
// Created by geoff on 6/9/2020.
//

#include "Monster.h"


Monster::Monster(float xPos, float yPos, float xDistance) {
    if(!monsterTexture.loadFromFile("GFGame/Pictures/SaltMonster.png"))
        std::cout << "Failed to Load Grass Image" << std::endl;

    monster.setTexture(monsterTexture);
    monster.setScale(3.f,3.f);

    this->xPos = xPos;

    startPos = xPos;
    endPos = startPos + xDistance;
    xSpeed = 2;

    monster.setPosition(xPos,yPos);
}

void Monster::draw(sf::RenderWindow &window) {
    window.draw(monster);
}

void Monster::update() {
    xPos = monster.getPosition().x;

    if(moveRight){
        xSpeed = 2;

        if(xPos + monster.getGlobalBounds().width >= endPos){
            moveRight = false;
            moveLeft = true;
        }
    }
    else if(moveLeft){
        xSpeed = -2;

        if(xPos <= startPos){
            moveRight = true;
            moveLeft = false;
        }
    }
    monster.move(xSpeed, 0);
}

float Monster::getTop() {
    return monster.getGlobalBounds().top;
}

float Monster::getHeight() {
    return monster.getGlobalBounds().height;
}

float Monster::getLeft() {
    return monster.getGlobalBounds().left;
}

float Monster::getWidth() {
    return monster.getGlobalBounds().width;
}


