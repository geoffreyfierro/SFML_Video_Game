//
// Created by geoff on 5/14/2020.
//

#ifndef SFML_PROJECT_GFGAME_H
#define SFML_PROJECT_GFGAME_H

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>
#include "Player.h"
#include "Background.h"
#include "Map.h"
#include "MonsterArray.h"
#include "Hearts.h"
#include "WonGameScreen.h"
#include "LostGameScreen.h"

class GFGame : public Game{
private:
    GameText *logo;

    sf::Font *titleFont;
    sf::Text *titleText;
    sf::Text *subTitleText;
    sf::View *view;

    Background *background;

    bool startGame;

    Player *player;
    Map *map;
    FinishFlag *flag;
    Hearts *hearts;
    MonsterArray *monster;

    WonGameScreen *wonGameScreen;
    LostGameScreen *lostGameScreen;

public:
    GFGame();
    ~GFGame();

    virtual void start(sf::RenderWindow& window);
    virtual void addEvents(sf::RenderWindow &window);
    virtual void addEvents(const sf::RenderWindow &window, sf::Event& event);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void exit();
};


#endif //SFML_PROJECT_GFGAME_H
