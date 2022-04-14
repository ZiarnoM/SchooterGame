//
// Created by michal on 11.04.2022.
//

#include "Bullet.h"
#include <math.h>

Bullet::Bullet() {

}
Bullet::Bullet(sf::Texture * texture,float pos_x,float pos_y, float dir_x, float dir_y, float movement_speed) {
    this->bulletShape.setTexture(*texture);
    this->bulletShape.setPosition(pos_x,pos_y);
    //this->bulletShape.scale(sf::Vector2f(2, 2));
    const float PI = 3.14159265;
    float rotation = (atan2(dir_y, dir_x)) * 180 / PI;
    this->bulletShape.setRotation(rotation+90);
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

