//
// Created by geoff on 6/9/2020.
//

#ifndef SFML_PROJECT_MONSTER_H
#define SFML_PROJECT_MONSTER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Monster {
private:
    sf::Sprite monster;
    sf::Texture monsterTexture;

    float xPos;
    float startPos, endPos;
    float xSpeed;
    bool moveLeft, moveRight;


public:
    Monster(float xPos, float yPos, float xDistance);
    void update();
    float getTop();
    float getHeight();
    float getLeft();
    float getWidth();

    void draw(sf::RenderWindow &window);
};


#endif //SFML_PROJECT_MONSTER_H
