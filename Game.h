#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#ifndef NAUKA_PIERWSZYPROJEKT_GAME_H
#define NAUKA_PIERWSZYPROJEKT_GAME_H


class Game {

private:

    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;

    void initVariables();

    void initWindow();

public:
    Game();

    virtual ~Game();

    const bool running() const;

    void pollEvents();

    void update();

    void render();

};


#endif
