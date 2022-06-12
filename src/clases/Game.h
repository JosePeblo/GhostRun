#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <Player.h>
#include <Enemy.h>
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
    //std::vector<Enemy> enemies;
    Enemy* enemies[5];

    // Private Functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemies();

    public:
    // Constructores y destructores
    Game();
    ~Game();
    // Metodos
    const bool getWindowIsOpen() const;
    void pollEvents();
    void onInput();
    void checkCollisions(const std::vector<Line>&,const std::vector<Line>&);
    void onUpdate();
    void onRender();
};

#endif