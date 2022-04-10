//
// Created by michal on 07.04.2022.
//

#include <iostream>
#include "Player.h"
#include <math.h>

void Player::initVariables() {
    this->movementSpeed = 10.f;
}

void Player::initPlayer() {
    this->initTexture();
    playerSprite.scale(sf::Vector2f(0.1, 0.1));
}
void Player::initTexture() {
    if (!this->texture.loadFromFile("../textures/player.png")) {
        std::cout << "Could not load player texture" << std::endl;
    }
    playerSprite.setTexture(texture);
    this->playerSprite.setOrigin(texture.getSize().x/2,texture.getSize().y/2);
}
Player::Player(float x, float y) {
    this->playerSprite.setPosition(x, y);
    this->initVariables();
    this->initPlayer();
}

Player::~Player() {

}

void Player::update(const sf::RenderTarget *target, sf::Vector2i mousePosition) {
    this->updateInput();
    // rotate player to mouse
    this->rotatePlayer(mousePosition);
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

void Player::rotatePlayer(sf::Vector2i position) {
    sf::FloatRect playerBounds = this->playerSprite.getGlobalBounds();
    // exit if mouse is over player
    if (!((position.x<=playerBounds.left ||position.x>=playerBounds.left+playerBounds.width)||
    (position.y<=playerBounds.top ||position.y>=playerBounds.top+playerBounds.height))) {
        return;
    }
        const float PI = 3.14159265;

        float dx = playerBounds.left + playerBounds.width / 2 - position.x;
        float dy = playerBounds.top + playerBounds.height / 2 - position.y;

        float rotation = (atan2(dy, dx)) * 180 / PI;
//        std::cout << this->playerSprite.getOrigin().x << "\n";
//        this->playerSprite.setOrigin(playerBounds.width/2,playerBounds.height/2);
        this->playerSprite.setRotation(rotation - 90);

}



