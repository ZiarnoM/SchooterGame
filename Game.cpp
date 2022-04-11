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

void Game::initPlayer() {
    this->player = new Player();
}

void Game::initTexture() {
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("../textures/bullet.png");
}

// Constructors and Destructors
Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initTexture();
    this->initPlayer();
}

Game::~Game() {
    delete this->window;
    delete this->player;
    //Delete texture
    for (auto &i: this->textures) {
        delete i.second;
    }
    for (auto &i: this->bullets) {
        delete i;
    }
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
    this->updateInput();
    this->updateBullets();

    sf::Vector2i mousePosition = sf::Mouse::getPosition(*this->window);
    this->player->update(this->window, mousePosition);
}

void Game::render() {
    this->window->clear(sf::Color(255, 0, 255, 255));
    // render stuff
    this->player->render(this->window);
    for (auto *bullet: this->bullets) {
        bullet->render(this->window);
    }
    this->window->display();
}

void Game::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAttack()) {
//        this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x,this->player->getPos().y,0.f,-1.f,5.f));
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y,
                                           this->player->getBulletDir().x, this->player->getBulletDir().y, 5.f));
    }
}

void Game::updateBullets() {
    unsigned counter = 0;
    for (auto *bullet: this->bullets) {
        bullet->update();
        // up,right,bottom,left
        if (
                (bullet->getBounds().top + bullet->getBounds().height < 0.f) ||
                (bullet->getBounds().left >= this->window->getSize().x) ||
                (bullet->getBounds().top - bullet->getBounds().height >= this->window->getSize().x) ||
                (bullet->getBounds().left <= 0.f)
                ) {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
        }
        ++counter;
    }
}




