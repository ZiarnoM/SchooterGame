#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
    Game game;

    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (game.running())
    {
        game.update();
        game.render();

    }
}
