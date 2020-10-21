//
// Created by geoff on 6/10/2020.
//

#include "MonsterArray.h"

MonsterArray::MonsterArray() {
    this->addMonster(2500,1044, 375);
    this->addMonster(3600, 1150, 375);
    this->addMonster(3600, 750, 375);
    this->addMonster(5425, 950, 225);
    this->addMonster(5800, 1100, 225);
    this->addMonster(6175, 1195, 225);

}

void MonsterArray::addMonster(float x, float y, float xDistance) {
    monster.push_back(new Monster(x,y, xDistance));
}

void MonsterArray::update() {
    for(int i = 0; i < monster.size(); i++){
        monster[i]->update();
    }
}
