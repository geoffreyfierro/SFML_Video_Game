//
// Created by geoff on 6/10/2020.
//

#ifndef SFML_PROJECT_MONSTERARRAY_H
#define SFML_PROJECT_MONSTERARRAY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Monster.h"

class MonsterArray {
public:
    std::vector<Monster*> monster;

    MonsterArray();
    void addMonster(float x, float y, float xDistance);
    void update();

};


#endif //SFML_PROJECT_MONSTERARRAY_H
