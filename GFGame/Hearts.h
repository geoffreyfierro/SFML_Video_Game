//
// Created by geoff on 6/9/2020.
//

#ifndef SFML_PROJECT_HEARTS_H
#define SFML_PROJECT_HEARTS_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include <vector>

class Hearts {
private:
    sf::Texture heartTexture;
    std::vector<sf::Sprite> hearts;
    int lives;

public:
    Hearts();
    void update(Player player);
    void draw(sf::RenderWindow &window);
};


#endif //SFML_PROJECT_HEARTS_H
