//
// Created by michal on 05.04.2022.
//

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef SCHOOTERGAME_GAME_H
#define SCHOOTERGAME_GAME_H


class Game {

private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event ev;

    void initVariables();
    void initWindow();

public:
    // Constructors and Destructors
    Game();
    ~Game();

    const bool running() const;

    void pollEvents();

    void update();

    void render();

};


#endif //SCHOOTERGAME_GAME_H
