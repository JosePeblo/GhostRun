#ifndef GAME_H
#define GAME_H

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
    // Metodos
    const bool getWindowIsOpen() const;
    void pollEvents();
    void onUpdate();
    void onRender();
    void updateEnemies();
    bool checkCollision(Entity&,const std::vector<Line>&,const std::vector<Line>&);
    bool checkCollision(Entity&,Entity&);

    private:
    // Variables
    sf::VideoMode videoMode;
    sf::Event ev;  
    sf::RenderWindow* window;
    Map* map;
    Player* player;
    std::vector<Enemy*> enemies;
    int enemyCount = 0;

    // Private Functions
    void initVariables();
    void initWindow();
    void initPlayer();
    void initEnemies();

};

#endif