//
// Created by geoff on 5/27/2020.
//

#include "Player.h"

Player::Player() {
    if(!snailRight.loadFromFile("GFGame/Pictures/SnailRight.png"))
        std::cout << "Snail Image Failed to Load" << std::endl;
    if(!snailLeft.loadFromFile("GFGame/Pictures/SnailLeft.png"))
        std::cout << "Snail Image Failed to Load" << std::endl;

    player.setTexture(snailRight);

    player.setScale(3.f,3.f);
    player.setPosition((1035),1920/2);
    //player.setPosition(4735,750);

    xSpeed = 0;
    ySpeed = 0;

    accelGrav = 0.5f;
    maxGrav = 5.f;
    jumpHeight = 15.f;

    lives = 3;

    onGround = false;
    isCollided = false;
    hitMonster = false;

    wonGame = false;

}

void Player::draw(sf::RenderWindow &window) {
    window.draw(player);
}

void Player::update(Map map, MonsterArray monster, FinishFlag flag) {
    if(hitMonster){
        player.setPosition(1035.f,960.f);
        lives--;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && onGround)
        ySpeed = -jumpHeight;

    if(!onGround){
        ySpeed += accelGrav;
        if(ySpeed > maxGrav)
            ySpeed = maxGrav;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        ySpeed = 5;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        player.setTexture(snailLeft);
        xSpeed = -5;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.setTexture((snailRight));
        xSpeed = 5;
    }

    if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
        xSpeed = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        xSpeed = 0;

    if(player.getGlobalBounds().left < 960 && !sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        xSpeed = 0;
    }
    if(player.getGlobalBounds().left + player.getGlobalBounds().width > 6720 && !sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        xSpeed = 0;
    }

    leftSide = player.getGlobalBounds().left;
    leftSide + player.getGlobalBounds().width;
    topSide = player.getGlobalBounds().top;
    topSide + player.getGlobalBounds().height;

    player.move(xSpeed,0);
    collision(xSpeed, 0, map);

    onGround = false;
    player.move(0,ySpeed);
    collision(0, ySpeed, map);

    hitMonster = false;
    monsterCollision(monster);

    checkGameWin(flag);

}

void Player::collision(float xVol, float yVol, Map platform) {
    for(int i = 0; i < platform.platforms.size(); i++) {
        isCollided = (player.getGlobalBounds().left + player.getGlobalBounds().width) > platform.platforms[i]->getLeftSide() &&
                     player.getGlobalBounds().top < platform.platforms[i]->getBottomSide() &&
                     (player.getGlobalBounds().top + player.getGlobalBounds().height) > platform.platforms[i]->getTopSide() &&
                     player.getGlobalBounds().left < platform.platforms[i]->getRightSide();

        if (isCollided) {
            if (xVol > 0.f) {
                player.setPosition(platform.platforms[i]->getLeftSide() - player.getGlobalBounds().width, player.getPosition().y);
                xSpeed = 0.f;
            }
            else if (xVol < 0.f) {
                player.setPosition(platform.platforms[i]->getRightSide(), player.getPosition().y);
                xSpeed = 0.f;
            }
            else if (yVol > 0.f) {
                player.setPosition(player.getPosition().x, platform.platforms[i]->getTopSide() - player.getGlobalBounds().height);
                ySpeed = 0.f;
                onGround = true;
            }
            else if (yVol < 0.f) {
                player.setPosition(player.getPosition().x, platform.platforms[i]->getBottomSide());
                ySpeed = 0.f;
            }

        }
    }
}

sf::Vector2f Player::getPositionCenter() {
    return sf::Vector2f(player.getPosition().x + player.getGlobalBounds().width/2.f, player.getPosition().y + player.getGlobalBounds().height/2.f);
}

void Player::monsterCollision(MonsterArray monster) {
    for(int i = 0; i <monster.monster.size(); i++){
        if(player.getGlobalBounds().intersects(sf::Rect<float> (monster.monster[i]->getLeft(), monster.monster[i]->getTop(), monster.monster[i]->getWidth(), monster.monster[i]->getHeight())))
            hitMonster = true;
    }

}

int Player::getLives() {
    return lives;
}

void Player::checkGameWin(FinishFlag flag) {
    if(player.getGlobalBounds().intersects(sf::Rect<float> (flag.getLeftSide(), flag.getTopSide(), flag.getWidth(), flag.getHeight())))
        wonGame = true;
}

bool Player::getGameWon() {
    return wonGame;
}

bool Player::isDead() {
    return (lives <= 0);
}
