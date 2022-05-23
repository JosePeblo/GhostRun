#ifndef GAME_H
#define GAME_H
/*
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
*/
#include <iostream>

#include <Player.h>

class Game
{
    private:
    // Variables
    sf::VideoMode videoMode; //Probablemente quitalas
    sf::Event ev;   ///////////////////////////////

    sf::RenderWindow* window;
    Player* player;
    Player* bob;

    // Private Functions
    void initVariables();
    void initWindow();
    void initPlayer();

    public:
    // Constructores y destructores
    Game();
    ~Game();
    // Metodos
    const bool getWindowIsOpen() const;
    void pollEvents();
    void onUpdate();
    void onRender();
};
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlayer();
}
Game::~Game()
{
    delete this->player;
    delete this->window;
}
//Funciones privadas
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}
void Game::initPlayer()
{
    this->player = new Player(0.f,0.f,64.f,"assets/textures/map.png");
    this->bob = new Player(320.f,320.f,1.f,"assets/textures/void.png");
}

void Game::initVariables()
{
    this->bob = nullptr;
    this->player = nullptr;
    this->window = nullptr;
}
void Game::initWindow()
{
    this->videoMode.height = 704;
    this->videoMode.width = 704;
    this->window = new sf::RenderWindow(this->videoMode, "Totally not pokemon", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);    
}

// Metodos
void Game::pollEvents()
{
    // Event polling
    while(this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if(this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}
void Game::onUpdate()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move('u');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move('d');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move('r');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move('l');
    
    this->pollEvents();
}
/**
 * -Limpiar frame previo 
 * -Renderizar objetos
 * -Mostrar frame en la ventana
 * @return void
 */
void Game::onRender()
{
    this->window->clear(); // Clear old frame
    // Draw game objets
    this->player->render(*this->window);
    this->bob->render(*this->window);
    this->window->display(); // Tell the app that the window is done drawing
}


#endif