//
// Created by michal on 07.04.2022.
//

#include <iostream>
#include "Player.h"
#include <math.h>

void Player::initVariables() {
    this->movementSpeed = 5.f;
    this->attackCooldownMax = 5.f;
    this->attackCooldown = this->attackCooldownMax;
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

    this->playerSprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

Player::Player(float x, float y) {
    this->playerSprite.setPosition(x, y);
    this->initVariables();
    this->initPlayer();
}

Player::~Player() {

}

void Player::update(const sf::RenderTarget *target, sf::Vector2i mousePosition) {
    // rotate player to mouse
    this->rotatePlayer(mousePosition);
    //collision
    this->updateWindowBoundsCollision(target);
    this->updateAttack();
}


void Player::render(sf::RenderTarget *target) {
    target->draw(this->playerSprite);
}

void Player::updateAttack() {
    if (this->attackCooldown < this->attackCooldownMax)
        this->attackCooldown += 0.5f;

}

void Player::updateWindowBoundsCollision(const sf::RenderTarget *target) {
    //if player touch window border after move in specific direction, then move it in opposite
    //left border
    if (this->playerSprite.getGlobalBounds().left <= 0.f) {
        this->playerSprite.move(this->movementSpeed, 0.f);
    }
    //right border
    if (this->playerSprite.getGlobalBounds().left + this->playerSprite.getGlobalBounds().width >= target->getSize().x) {
        this->playerSprite.move(-this->movementSpeed, 0.f);
    }
    //top border
    if (this->playerSprite.getGlobalBounds().top <= 0.f) {
        this->playerSprite.move(0.f, this->movementSpeed);
    }
    //bottom border
    if (this->playerSprite.getGlobalBounds().top + this->playerSprite.getGlobalBounds().height >= target->getSize().y) {
        this->playerSprite.move(0.f, -this->movementSpeed);
    }
}

void Player::rotatePlayer(sf::Vector2i position) {
    sf::FloatRect playerBounds = this->playerSprite.getGlobalBounds();
    // exit if mouse is over player
    if (!((position.x <= playerBounds.left || position.x >= playerBounds.left + playerBounds.width) ||
          (position.y <= playerBounds.top || position.y >= playerBounds.top + playerBounds.height))) {
        return;
    }
    const float PI = 3.14159265;

    float dx = playerBounds.left + playerBounds.width / 2 - position.x;
    float dy = playerBounds.top + playerBounds.height / 2 - position.y;
    float dc = sqrt(pow(dx,2.0f)+pow(dy,2.0f));

    this->bulletDirection.x = -dx/dc;
    this->bulletDirection.y = -dy/dc;

    float rotation = (atan2(dy, dx)) * 180 / PI;
    this->playerSprite.setRotation(rotation);
}

void Player::move(float dirX, float dirY) {
    this->playerSprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

const sf::Vector2f &Player::getPos() const {
    return this->playerSprite.getPosition();
}

const bool Player::canAttack() {
    if (this->attackCooldown >= this->attackCooldownMax) {
        this->attackCooldown = 0.f;
        return true;
    }
    return false;
}

const sf::Vector2f &Player::getBulletDir() const {
    return this->bulletDirection;
}

