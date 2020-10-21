//
// Created by geoff on 5/14/2020.
//

#include "GFGame.h"

GFGame::GFGame() {
    image_path = "GFGame/Pictures/thumbnail.png";
    title = "Snail Explorer";
    logo = new GameText(title, 96, sf::Vector2f(0,0));

    titleFont = new sf::Font();
    titleFont->loadFromFile("GFGame/Fonts/CHICKEN_Pie.ttf");
    titleText = new sf::Text(title, *titleFont, 96);
    subTitleText = new sf::Text("Click to Start", *titleFont, 48);



    view = new sf::View(sf::Vector2f(0.f,0.f), sf::Vector2f(1920,1080));
    startGame = false;

    background = new Background();
    player = new Player();
    map = new Map();
    flag = new FinishFlag();
    monster = new MonsterArray();
    hearts = new Hearts();

    wonGameScreen = new WonGameScreen();
    lostGameScreen = new LostGameScreen();
}

void GFGame::start(sf::RenderWindow &window) {
    logo->getText()->setPosition(window.getSize().x/2 -logo->getText()->getGlobalBounds().width/2, window.getSize().y/2 -logo->getText()->getGlobalBounds().height/2 );
    titleText->setPosition(window.getSize().x/2 - titleText->getGlobalBounds().width/2,window.getSize().y/2 - titleText->getGlobalBounds().height/2);
    subTitleText->setPosition(window.getSize().x/2 - subTitleText->getGlobalBounds().width/2, titleText->getPosition().y + (titleText->getGlobalBounds().height*2));

    window.getView();


}

void GFGame::addEvents(sf::RenderWindow &window) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        startGame = true;
    }

    monster->update();
    player->update(*map, *monster, *flag);
    hearts->update(*player);
    view->setCenter(player->getPositionCenter());
}

void GFGame::addEvents(const sf::RenderWindow &window, sf::Event &event) {

}

void GFGame::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!startGame){
        window.draw(*titleText);
        window.draw(*subTitleText);

    }
    else if(startGame){
        window.setView(*view);
        background->setBackgorund(dynamic_cast<sf::RenderWindow &>(window));
        for(int i = 0; i < map->platforms.size(); i++){
            map->platforms[i]->draw(dynamic_cast<sf::RenderWindow &>(window));
        }
        for(int i = 0; i < monster->monster.size(); i++){
            monster->monster[i]->draw(dynamic_cast<sf::RenderWindow &>(window));
        }
        player->draw(dynamic_cast<sf::RenderWindow &>(window));
        hearts->draw(dynamic_cast<sf::RenderWindow &>(window));
        flag->draw(dynamic_cast<sf::RenderWindow &>(window));
        wonGameScreen->draw(dynamic_cast<sf::RenderWindow &>(window), *player);
        lostGameScreen->draw(dynamic_cast<sf::RenderWindow &>(window), *player);
    }

}

void GFGame::exit() {
    this->~GFGame();
}

GFGame::~GFGame() {
    delete logo;
    delete titleFont;
    delete titleText;
    delete subTitleText;
    delete view;
    delete player;
    delete map;
    delete monster;
    delete hearts;
    delete flag;
}
