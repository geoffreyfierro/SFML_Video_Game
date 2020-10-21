//
// Created by geoff on 6/10/2020.
//

#include "WonGameScreen.h"

WonGameScreen::WonGameScreen() {
    gameFont.loadFromFile("GFGame/Fonts/CHICKEN_Pie.ttf");
    wonText.setFont(gameFont);
    wonText.setString("YOU WIN!");
    wonText.setCharacterSize(106);
    wonText.setFillColor(sf::Color::White);
    background.setSize(sf::Vector2f(1920.f,1080.f));
    background.setFillColor(sf::Color::Black);



}

void WonGameScreen::draw(sf::RenderWindow &window, Player player) {
    if(player.getGameWon()) {
        background.setPosition(player.getPositionCenter().x - background.getGlobalBounds().width/2, player.getPositionCenter().y - background.getGlobalBounds().height/2);
        wonText.setPosition(player.getPositionCenter().x - wonText.getGlobalBounds().width/2, player.getPositionCenter().y);
        window.draw(background);
        window.draw(wonText);
    }
}
