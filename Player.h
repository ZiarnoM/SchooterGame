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
    void initTexture();

public:
    Player(float x = 200.f, float y=200.f);
    virtual ~Player();

    void updateInput();
    void updateWindowBoundsCollision(const sf::RenderTarget* target);
    void update(const sf::RenderTarget* target, sf::Vector2i mousePosition);
    void render(sf::RenderTarget* target);
    void rotatePlayer(sf::Vector2i mousePosition);
};


#endif //SCHOOTERGAME_PLAYER_H
