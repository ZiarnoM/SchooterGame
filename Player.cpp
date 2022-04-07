//
// Created by michal on 07.04.2022.
//

#include <iostream>
#include "Player.h"

void Player::initVariables(){

}
void Player::initPlayer(){
    if (!this->texture.loadFromFile("../textures/player.png")) {
        std::cout << "Could not load player texture" << std::endl;
    }
    playerSprite.setTexture(texture);
    playerSprite.setPosition(sf::Vector2f(100,100));
    playerSprite.scale(sf::Vector2f(0.1,0.1));
}

Player::Player() {
this->initVariables();
this->initPlayer();
}
Player::~Player() {

}

void Player::update() {

}

void Player::render(sf::RenderTarget * target) {
    target->draw(this->playerSprite);
}
