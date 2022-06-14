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
    this->window = new sf::RenderWindow(this->videoMode, "Lame ghost game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);    
}

void Game::initPlayer()
{
    this->player = new Player("assets/textures/player.png",sf::Vector2f(16.f,20.f),4,sf::Vector2f(324,320),20,7.f);
    this->map = new Map("assets/textures/mansion.png","assets/textures/mansion.png");    
}

void Game::initEnemies()
{
    for(int i = enemyCount; i < 5; i++)
    {
        enemies.push_back(new Enemy("assets/textures/phantom.png",sf::Vector2f(16.f,16.f),4,sf::Vector2f(rand()%780+1,rand()%780+1),20,3.f));
    }
    enemyCount = enemies.size();
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

void Game::updateEnemies()
{
    enemyCount = enemies.size();
    if(enemyCount < 5)
        this->initEnemies();
    this->enemies[0]->findPlayer(*player);
    if(this->checkCollision(*player,*enemies[0]))
        std::cout<<"Muerteeeeeeee!!!\n";
}

void Game::onUpdate()
{
    // Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        this->player->move('u');
        this->checkCollision(*player,map->getRoofs(),map->getWalls(),true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->player->move('d');
        this->checkCollision(*player,map->getRoofs(),map->getWalls(),true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->player->move('r');
        this->checkCollision(*player,map->getRoofs(),map->getWalls(),true);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->player->move('l');
        this->checkCollision(*player,map->getRoofs(),map->getWalls(),true);
    }

    //para matar//    this->enemies.erase(enemies.begin(),enemies.begin()+1);

    this->updateEnemies();
    this->pollEvents();
    this->player->update();
    this->map->update(*player);
    
}

void Game::onRender()
{
    /**
     * -Limpiar frame previo 
     * -Renderizar objetos
     * -Mostrar frame en la ventana
     * @return void
     */
    this->window->clear();
    this->map->render(*this->window);
    this->player->render(*this->window);
    for(int i = 0; i < 5; i++)
    {
        this->enemies[i]->render(*this->window);
    }
    this->window->display();
}
bool Game::checkCollision(Entity& entity,Entity& colide)
{
    Line auxLine;
    std::vector<Line> roofs;
    std::vector<Line> walls;
    roofs.reserve(2);
    walls.reserve(2);

    auxLine.pointA = sf::Vector2i(colide.getPos());
    auxLine.pointB = sf::Vector2i(colide.getPos().x+colide.getSize().x,colide.getPos().y);
    roofs.emplace_back(auxLine);
    auxLine.pointA = sf::Vector2i(colide.getPos().x,colide.getPos().y+colide.getSize().y);
    auxLine.pointB = sf::Vector2i(colide.getPos().x+colide.getSize().x,colide.getPos().y+colide.getSize().y);
    roofs.emplace_back(auxLine);
    auxLine.pointA = sf::Vector2i(colide.getPos());
    auxLine.pointB = sf::Vector2i(colide.getPos().x,colide.getPos().y+colide.getSize().y);
    walls.emplace_back(auxLine);
    auxLine.pointA = sf::Vector2i(colide.getPos().x+colide.getSize().x,colide.getPos().y);
    auxLine.pointB = sf::Vector2i(colide.getPos().x+colide.getSize().x,colide.getPos().y+colide.getSize().y);
    walls.emplace_back(auxLine);
    return checkCollision(entity,roofs,walls,false);
}
bool Game::checkCollision(Entity& entity,const std::vector<Line>& roofs,const std::vector<Line>& walls,bool move)
{
    bool colide = false;
    for(int i = 0; i < walls.size(); i++)
    {
        // For vertical walls
        if(entity.getPos().x<walls[i].pointA.x && 
        entity.getPos().x + entity.getSize().x > walls[i].pointA.x &&
        entity.getPos().y < walls[i].pointB.y &&
        entity.getPos().y + entity.getSize().y > walls[i].pointA.y)
        {   
            colide = true;
            if(move)
            {
                switch (entity.getDirection())
                {
                    case 'l':
                        entity.setPositionX(walls[i].pointA.x);
                        break;
                    case 'r':
                        entity.setPositionX(walls[i].pointA.x-entity.getSize().x);
                        break;
                }
            }
        }   
    }
    for(int i = 0; i < roofs.size(); i++)
    {
        if(entity.getPos().y<roofs[i].pointA.y &&
        entity.getPos().y+entity.getSize().y>roofs[i].pointA.y &&
        entity.getPos().x < roofs[i].pointB.x &&
        entity.getPos().x + entity.getSize().x>roofs[i].pointA.x)
        {
            colide = true;
            if(move)
            {
                switch (entity.getDirection())
                {
                    case 'u':
                        entity.setPositionY(roofs[i].pointA.y);
                        break;
                    case 'd':
                        entity.setPositionY(roofs[i].pointA.y-entity.getSize().y);
                        break;
                }
            }
        }
    }
    return colide;
}
