//
// Created by geoff on 5/28/2020.
//

#include "Map.h"

void Map::addPlatform(float x, float y) {
    platforms.push_back(new Platform(x, y));
}

Map::Map() {
    //Stage 1
    for (int i = 960; i < 6720; i+=75)
        this->addPlatform(i,1545);
    for (int i = 1410; i < 1710; i +=75)
        this->addPlatform(i,1350);
    for (int i = 1975; i < 2275; i += 75)
        this->addPlatform(i,1350);
    for (int i = 1750; i < 1900; i += 75)
        this->addPlatform(i, 1150);
    for (int i = 2125; i < 2275; i += 75)
        this->addPlatform(i, 950);

    //Stage 2 Separator
    for (int x = 2500; x <= 2800; x += 75)
        for(int y = 1545; y >= 1095; y -= 75)
            this->addPlatform(x, y);
    for(int i = 1545; i >= 1320; i -= 75)
        this->addPlatform(2875,i);

    //Stage 2
    for (int i = 3000; i <= 3200; i += 75)
        this->addPlatform(i,900);
    for (int i = 3600; i <= 3950; i += 75)
        this->addPlatform(i, 1200);
    for (int i = 4150; i <= 4375; i += 75)
        this->addPlatform(i, 1000);
    for (int i = 3600; i <= 3950; i += 75)
        this->addPlatform(i, 800);
    for (int i = 4150; i <= 4375; i += 75)
        this->addPlatform(i, 600);

    //Stage 3 Separator
    for(int x = 4735; x <= 5035; x += 75)
        for(int y = 1545; y >= 795; y -= 75)
            this->addPlatform(x,y);
    for(int i = 1545; i >= 1000; i -= 75)
        this->addPlatform(5110,i);
    for(int i = 1545; i >= 1200; i -= 75)
        this->addPlatform(5175,i);
    for(int i = 1545; i >= 1400; i -= 75)
        this->addPlatform(5250,i);

    //Stage 3
    for (int x = 5425; x <= 5575; x += 75)
        this->addPlatform(x, 1000);
    for (int x = 5800; x <= 5950; x += 75)
        this->addPlatform(x, 1150);

    //Final Separator
    for(int x = 6175; x <= 6325; x += 75)
        for(int y = 1545; y >= 1245; y -= 75)
            this->addPlatform(x,y);
}

