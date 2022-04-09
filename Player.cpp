//
// Created by michal on 07.04.2022.
//

#include <iostream>
#include "Player.h"

void Player::initVariables() {
    this->movementSpeed = 10.f;
}

void Player::initPlayer() {
    if (!this->texture.loadFromFile("../textures/player.png")) {
        std::cout << "Could not load player texture" << std::endl;
    }
    playerSprite.setTexture(texture);
    playerSprite.scale(sf::Vector2f(0.1, 0.1));
}

Player::Player(float x, float y) {
    this->playerSprite.setPosition(x, y);
    this->initVariables();
    this->initPlayer();
}

Player::~Player() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

    }
}

void Player::update(const sf::RenderTarget *target) {
    this->updateInput();
    //collision
    this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget *target) {
    target->draw(this->playerSprite);
}

void Player::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        this->playerSprite.move(0.f, -this->movementSpeed);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        this->playerSprite.move(0.f, this->movementSpeed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        this->playerSprite.move(-this->movementSpeed, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        this->playerSprite.move(this->movementSpeed, 0.f);
    }
}

void Player::updateWindowBoundsCollision(const sf::RenderTarget *target) {
    //left
    if (this->playerSprite.getGlobalBounds().left <= 0.f) {
        this->playerSprite.setPosition(0.f, this->playerSprite.getGlobalBounds().top);
    }
    //right
    if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= target->getSize().x) {
        this->playerSprite.setPosition(
                target->getSize().x - this->playerSprite.getGlobalBounds().width,
                this->playerSprite.getGlobalBounds().top
        );
    }
    //top
    if (this->playerSprite.getGlobalBounds().top <= 0.f) {
        this->playerSprite.setPosition(this->playerSprite.getGlobalBounds().left, 0.f);
    }
    //bottom
    if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= target->getSize().y) {
        this->playerSprite.setPosition(
                this->playerSprite.getGlobalBounds().left,
                target->getSize().y - this->playerSprite.getGlobalBounds().height
        );
    }
}
