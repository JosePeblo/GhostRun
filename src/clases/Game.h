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
    Player* background;
    Player* player;

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
    void onInput();
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
    delete this->background;
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
    this->background = new Player("assets/textures/map.png",sf::Vector2f(176.f,176.f),4);
    this->player = new Player("assets/textures/player.png",sf::Vector2f(16.f,20.f),4,sf::Vector2f(320,305));
}

void Game::initVariables()
{
    this->player = nullptr;
    this->background = nullptr;
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

void Game::onInput()
{
    
}

void Game::onUpdate()
{
    // Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        this->background->move('u');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        this->background->move('d');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        this->background->move('r');
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        this->background->move('l');
    
    this->pollEvents();
}

void Game::onRender()
{
    /**
 * -Limpiar frame previo 
 * -Renderizar objetos
 * -Mostrar frame en la ventana
 * @return void
 */
    this->window->clear(); // Clear old frame
    // Draw game objets
    this->background->render(*this->window);
    this->player->render(*this->window);

    this->window->display(); // Tell the app that the window is done drawing
}


#endif