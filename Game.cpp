//
// Created by michal on 05.04.2022.
//

#include "Game.h"

void Game::initVariables() {
    this->endGame = false;
    this->window = nullptr;
}

void Game::initWindow() {
    sf::Image icon;
    icon.loadFromFile("../textures/logo.png"); // File/Image/Pixel
    this->videoMode = sf::VideoMode(500, 500);
    this->window = new sf::RenderWindow(this->videoMode, "Schooter Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setIcon(32, 32, icon.getPixelsPtr());
    this->window->setFramerateLimit(60);
}

// Constructors and Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

const bool Game::running() const {
    return this->window->isOpen();
}

void Game::pollEvents() {

    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

void Game::update() {
    // listen to event and do stuff
    this->Game::pollEvents();
//update mouse position relative to window
    //std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";

    this->player.update(this->window);
}

void Game::render() {
    this->window->clear(sf::Color(255, 0, 255, 255));
    // render stuff
    this->player.render(this->window);
    this->window->display();
}