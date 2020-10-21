//
// Created by geoff on 6/10/2020.
//

#include "LostGameScreen.h"

LostGameScreen::LostGameScreen() {
    gameFont.loadFromFile("GFGame/Fonts/CHICKEN_Pie.ttf");
    lostText.setFont(gameFont);
    lostText.setString("GAME OVER");
    lostText.setCharacterSize(106);
    lostText.setFillColor(sf::Color::White);
    background.setSize(sf::Vector2f(1920.f,1080.f));
    background.setFillColor(sf::Color::Black);
}

void LostGameScreen::draw(sf::RenderWindow &window, Player player) {
    if(player.isDead()) {
        background.setPosition(player.getPositionCenter().x - background.getGlobalBounds().width / 2,
                               player.getPositionCenter().y - background.getGlobalBounds().height / 2);
        lostText.setPosition(player.getPositionCenter().x - lostText.getGlobalBounds().width / 2,
                             player.getPositionCenter().y);
        window.draw(background);
        window.draw(lostText);
    }
}
