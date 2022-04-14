//
// Created by michal on 13.04.2022.
//

#include "GameWorld.h"
#include <fstream>
#include <map>
#include <iostream>

GameWorld::GameWorld() {
    setUpTiles();
}
void GameWorld::setUpTiles() {
    this->tiles.clear();
    readMapFile();
    float x = 0;
    float y = 0;
    for (auto &outer: this->map) {
        std::vector<GameTile *> hold;
        for (auto &inner: outer) {
            if (inner == '1') {
                hold.push_back(new GameTile("../Textures/wall.png", x, y, false));
            } else {
                hold.push_back(new GameTile("../Textures/floor.png", x, y, true));
            }
            x += 50.f;
        }
        y += 50.f;
        x = 0.f;
        tiles.push_back(hold);
        hold.clear();
    }
}

void GameWorld::readMapFile() {
    std::string mapFilePath("../Maps/map0.txt");
    char byte = 0;
    std::ifstream mapFile(mapFilePath);
    int x = 0;
    int y = 0;
    while (mapFile.get(byte)) {
        if(byte=='\n'){
            continue;
        }
        this->map[x][y] = byte;
        y++;
        if (y == 10) {
            x++;
            y = 0;
        }
    }
    mapFile.close();
}
void GameWorld::update(sf::RenderTarget *target) {
    for (int i = 0; i < this->gridSize; ++i) {
        for (int j = 0; j < this->gridSize; ++j) {
            target->draw(this->tiles[i][j]->tileSprite);
        }
    }
}
