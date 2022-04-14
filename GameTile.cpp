//
// Created by michal on 13.04.2022.
//

#include "GameTile.h"
#include <iostream>

GameTile::GameTile(std::string textureName,float x,float y,bool passable){
    if(!setUpSprite(textureName)){
        return;
    }
    this->pos = sf::Vector2f(x,y);
    this->tileSprite.setPosition(pos);
    this->isPassable = passable;
}

bool GameTile::setUpSprite(std::string textureName) {
    if (!this->texture.loadFromFile(textureName)) {
        std::cout << "Could not load player texture" << std::endl;
        return false;
    }
    this->tileSprite.setTexture(texture);
    return true;
}
