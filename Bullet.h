//
// Created by michal on 11.04.2022.
//
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#ifndef SCHOOTERGAME_BULLET_H
#define SCHOOTERGAME_BULLET_H


    class Bullet {
    private:
        sf::Sprite bulletShape;
        sf::Texture* texture;
        sf::Vector2f directrion;
        float movementSpeed;

    public:
    Bullet();
        Bullet(sf::Texture* texture,float pos_x,float pos_y, float dir_x,float dir_y,float movement_speed);

        virtual ~Bullet();

        const sf::FloatRect getBounds() const;

        void update();
        void render(sf::RenderTarget* target);
    };


#endif //SCHOOTERGAME_BULLET_H
