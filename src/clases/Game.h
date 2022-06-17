/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * El objeto juego se encarga de definir la lógica del juego y crear los demás
 * objetos que correrán dentro de el. El estandar en la industria de los juegos
 * es la creación de un objeto Game que se sus taréas se resumen en Update y 
 * Render. Toda la lógica se llama en la función Update y al final Render se 
 * encarga de dibujar en la ventana.
 */
#ifndef GAME_H
#define GAME_H

// Librerías de SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <Player.h>
#include <Enemy.h>
#include <Map.h>

class Game
{
    public:
    // Constructores y destructores
    Game();
    ~Game();
    // Métodos
    const bool getWindowIsOpen() const;
    void pollEvents();
    void onUpdate();
    void onRender();
    void updateEnemies();
    bool checkCollision(Entity&,const std::vector<Line>&,const std::vector<Line>&,bool);
    bool checkCollision(Player&,Entity&);

    private:
    // Variables
    sf::VideoMode videoMode;
    sf::Event ev;  
    sf::RenderWindow* window;
    Map* map;
    Player* player;
    Enemy* enemy;

    // Funciones privadas
    void initVariables();
    void initWindow();
    void initPlayer();
    void initMap();
    void initEnemies();

};

#endif