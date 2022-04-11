//
// Created by michal on 11.04.2022.
//

#include "Bullet.h"

Bullet::Bullet() {

}
Bullet::Bullet(sf::Texture * texture,float pos_x,float pos_y, float dir_x, float dir_y, float movement_speed) {
    this->bulletShape.setTexture(*texture);
    this->bulletShape.setPosition(pos_x,pos_y);
    this->directrion.x = dir_x;
    this->directrion.y = dir_y;
    this->movementSpeed = movement_speed;
    }

    Bullet::~Bullet() {

    }

    void Bullet::update() {
    this->bulletShape.move(this->movementSpeed * this->directrion);
    }

    void Bullet::render(sf::RenderTarget *target) {
        target->draw(this->bulletShape);
    }

const sf::FloatRect Bullet::getBounds() const {
    return this->bulletShape.getGlobalBounds();
}

