//
// Created by michal on 13.04.2022.
//

#ifndef SCHOOTERGAME_GAMETILE_H
#define SCHOOTERGAME_GAMETILE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

class GameTile {
public:
    bool isPassable;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite tileSprite;
    GameTile(std::string textureName,float x,float y,bool passable);
    bool setUpSprite(std::string textureName);
};


#endif //SCHOOTERGAME_GAMETILE_H
