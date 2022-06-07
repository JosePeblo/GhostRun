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
#include <Map.h>


class Game
{
    private:
    // Variables
    sf::VideoMode videoMode;
    sf::Event ev;  

    sf::RenderWindow* window;
    Map* map;
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

#endif