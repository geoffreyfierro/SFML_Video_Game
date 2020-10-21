//
// Created by geoff on 5/27/2020.
//

#ifndef SFML_PROJECT_PLAYER_H
#define SFML_PROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Platform.h"
#include "Map.h"
#include "Monster.h"
#include "MonsterArray.h"
#include "FinishFlag.h"

class Player{
private:
    sf::Sprite player;
    sf::Texture snailRight;
    sf::Texture snailLeft;

    int lives;
    float xSpeed, ySpeed;
    bool onGround, isCollided;
    bool hitMonster;

    bool wonGame;

    float topSide, leftSide;

    float accelGrav;
    float maxGrav;
    float jumpHeight;

protected:

public:
    Player();
    void update(Map map, MonsterArray monster, FinishFlag flag);
    void collision(float xVol, float yVol, Map map);
    void monsterCollision(MonsterArray monster);
    void checkGameWin(FinishFlag flag);

    int getLives();
    bool isDead();
    bool getGameWon();

    void draw(sf::RenderWindow &window);
    sf::Vector2f getPositionCenter();
};


#endif //SFML_PROJECT_PLAYER_H
