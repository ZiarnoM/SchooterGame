//
// Created by michal on 07.04.2022.
//
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#ifndef SCHOOTERGAME_PLAYER_H
#define SCHOOTERGAME_PLAYER_H


class Player {
private:
    sf::Texture texture;
    sf::Sprite playerSprite;

    float movementSpeed;

    void initVariables();
    void initPlayer();

public:
    Player(float x = 0.f, float y=0.f);
    virtual ~Player();

    void updateInput();
    void update(sf::RenderTarget* target);
    void render(sf::RenderTarget* target);
};


#endif //SCHOOTERGAME_PLAYER_H
