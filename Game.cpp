#include "Game.h"

void Game::initVariables() {
    this->window = nullptr;
}
void Game::initWindow() {
    this->videoMode.height=500;
    this->videoMode.width=500;
    this->window = new sf::RenderWindow(this->videoMode, "My first Game",sf::Style::Titlebar | sf::Style::Close);
    this -> window ->setFramerateLimit(144);

}

Game::Game() {
    this->initVariables();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}
const bool Game::running() const{
    return this->window->isOpen();
}

void Game::pollEvents(){

    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
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
    this->Game::pollEvents();
//opdate mouse position relative to window
    std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " " << sf::Mouse::getPosition(*this->window).y << "\n";
}

void Game::render() {
    this->window->clear(sf::Color(255,0,255,255));
    this->window->display();
}