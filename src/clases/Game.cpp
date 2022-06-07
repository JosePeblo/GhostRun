#include <Game.h>

Game::Game()
{
    this->initVariables();
    this->initWindow();
    this->initPlayer();
}

Game::~Game()
{
    delete this->map;
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
    this->player = new Player("assets/textures/player.png",sf::Vector2f(16.f,20.f),4,sf::Vector2f(320,355));
    this->map = new Map(*this->player,"assets/textures/map.png","assets/mapWalls/mapProto.png");    
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
    {
        this->player->move('u');
        this->map->checkCollision();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        this->player->move('d');
        this->map->checkCollision();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        this->player->move('r');
        this->map->checkCollision();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        this->player->move('l');
        this->map->checkCollision();
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
    

    this->window->display(); // Tell the app that the window is done drawing
}
