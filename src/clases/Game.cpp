#include <Game.h>

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initEnemies();
}

Game::~Game()
{
    delete this->map;
    delete this->player;
    delete this->window;
    for(int i = 0; i < 5; i++)
    {
        delete this->enemies[i];
    }
}
//Funciones privadas
const bool Game::getWindowIsOpen() const
{
    return this->window->isOpen();
}

void Game::initVariables()
{
    this->player = nullptr;
    this->map = nullptr;
    this->window = nullptr;
}

void Game::initWindow()
{
    this->videoMode.height = 704;
    this->videoMode.width = 704;
    this->window = new sf::RenderWindow(this->videoMode, "Totally not pokemon", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);    
}

void Game::initPlayer()
{
    this->player = new Player("assets/textures/player.png",sf::Vector2f(16.f,16.f),4,sf::Vector2f(320,355));
    this->map = new Map(*this->player,"assets/mapWalls/mapSpiral.png","assets/mapWalls/mapSpiral.png");    
}

void Game::initEnemies()
{
    for(int i = 0; i < 5; i++)
    {
        enemies[i] = new Enemy("assets/textures/void.png",sf::Vector2f(16.f,16.f),4,sf::Vector2f(rand()%780+1,rand()%780+1));
    }
}

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
void Game::checkCollisions(const std::vector<Line>& walls,const std::vector<Line>& roofs)
{
    for(int i = 0; i < walls.size(); i++)
    {
        // For vertical walls
        if(player->getPos().x<walls[i].pointA.x && 
        player->getPos().x + player->getSize().x > walls[i].pointA.x &&
        player->getPos().y < walls[i].pointB.y &&
        player->getPos().y + player->getSize().y > walls[i].pointA.y)
        {   
            switch (player->getDirection())
            {
                case 'l':
                    player->setPositionX(walls[i].pointA.x);
                    break;
                case 'r':
                    player->setPositionX(walls[i].pointA.x-player->getSize().x);
                    break;
            }
        }   
    }
    for(int i = 0; i < roofs.size(); i++)
    {
        if(player->getPos().y<roofs[i].pointA.y &&
        player->getPos().y+player->getSize().y>roofs[i].pointA.y &&
        player->getPos().x < roofs[i].pointB.x &&
        player->getPos().x + player->getSize().x>roofs[i].pointA.x)
        {
            switch (player->getDirection())
            {
                case 'u':
                    player->setPositionY(roofs[i].pointA.y);
                    break;
                case 'd':
                    player->setPositionY(roofs[i].pointA.y-player->getSize().y);
                    break;
            }
        }
    }
}

void Game::onUpdate()
{
    // Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->player->move('u');
        this->checkCollisions(map->walls,map->roofs);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->player->move('d');
        this->checkCollisions(map->walls,map->roofs);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->player->move('r');
        this->checkCollisions(map->walls,map->roofs);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->player->move('l');
        this->checkCollisions(map->walls,map->roofs);
    }
    
    for(int i = 0; i<5; i++)
    {
    char borrame;
    int borrameigual = rand()%4+1;
    switch (borrameigual)
    {
    case 1:
        borrame = 'u';
    break;
    case 2:
        borrame = 'd';
    break;
    case 3:
        borrame = 'l';
    break;
    case 4:
        borrame = 'r';
    break;
    }

    this->enemies[i]->move(borrame);
    this->enemies[i]->update();
    }

    this->pollEvents();
    this->player->update();
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
    this->map->render(*this->window);
    this->player->render(*this->window);
    for(int i = 0; i < 5; i++)
    {
        this->enemies[i]->render(*this->window);
    }
    

    this->window->display(); // Tell the app that the window is done drawing
}
