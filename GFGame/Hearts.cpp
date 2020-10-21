//
// Created by geoff on 6/9/2020.
//

#include "Hearts.h"

Hearts::Hearts() {
    if(!heartTexture.loadFromFile("GFGame/Pictures/Heart.png"))
        std::cout << "Could Not Load Heart Image" << std::endl;

    lives = 3;

    for (int i = 0; i < lives; i++)
        hearts.push_back(sf::Sprite(heartTexture));

    for (int i = 0; i < lives; i++)
        hearts[i].setScale(2.f,2.f);
}

void Hearts::update(Player player) {
    this->lives = player.getLives();

    for(int i = 0; i < lives; i++)
        hearts[i].setPosition(player.getPositionCenter().x - (950) + (i*50), player.getPositionCenter().y - 500);
}

void Hearts::draw(sf::RenderWindow &window) {
    for(int i = 0; i < lives; i++)
        window.draw(hearts[i]);
}
