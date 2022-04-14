//
// Created by michal on 05.04.2022.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Player.h"
#include "GameWorld.h"
#include<map>
#include "Bullet.h"
#ifndef SCHOOTERGAME_GAME_H
#define SCHOOTERGAME_GAME_H


class Game {

private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event ev;

    std::map<std::string,sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    Player* player;
    GameWorld* gameWorld;

    void initVariables();
    void initWindow();
    void initTexture();
    void initPlayer();
    void initWorldMap();

public:
    // Constructors and Destructors
    Game();
    virtual ~Game();

    const bool running() const;

    void pollEvents();

    void update();
    void updateInput();
    void updateBullets();
    void render();

};


#endif //SCHOOTERGAME_GAME_H
