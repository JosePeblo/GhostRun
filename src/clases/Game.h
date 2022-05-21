#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <Player.h>

class Game
{
    private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event ev;
    Player bob;

    // Private Functions
    void initVariables();
    void initWindow();

    public:
    // Constructores y destructores
    Game();
    ~Game();
    // Metodos
    const bool getWindowIsOpen() const;
    void initPlayer();
    void pollEvents();
    void onUpdate();
    void onRender();
};

// Constructores
Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlayer();
}
Game::~Game()
{
    delete this->window;
}
//Funciones privadas
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}
void Game::initPlayer()
{
    bob.setPos(100.f,230.f);
    bob.setSize(100.f);
    
}

void Game::initVariables()
{
    this->window = nullptr;
}
void Game::initWindow()
{
    this->videoMode.height = 480;
    this->videoMode.width = 640;
    this->window = new sf::RenderWindow(this->videoMode, "Totally not pokemon", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(144);    
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        bob.setPos(140.f,0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        bob.setPos(0.f,0.f);
    }

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
    this->window->draw(this->bob.getPlayer());
    this->window->display(); // Tell the app that the window is done drawing
}



#endif