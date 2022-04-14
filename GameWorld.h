//
// Created by michal on 13.04.2022.
//

#ifndef SCHOOTERGAME_GAMEWORLD_H
#define SCHOOTERGAME_GAMEWORLD_H

#include "GameTile.h"
#include <vector>


class GameWorld {
    sf::Vector2i playerPos;

    void setUpTiles();
    void setUpTilesv2();
    void readMapFile();

    char map[10][10];
public:
    int gridSize = 10;
    std::vector< std::vector<GameTile *> > tiles;

    GameWorld();
    void update(sf::RenderTarget *target);
};


#endif //SCHOOTERGAME_GAMEWORLD_H
