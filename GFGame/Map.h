//
// Created by geoff on 5/28/2020.
//

#ifndef SFML_PROJECT_MAP_H
#define SFML_PROJECT_MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Platform.h"


class Map {
private:


public:
    std::vector<Platform*> platforms;

    Map();
    void addPlatform (float x, float y);

};


#endif //SFML_PROJECT_MAP_H
