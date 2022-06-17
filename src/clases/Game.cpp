#include <Game.h>

Game::Game()
{
    /**
     * -Llama a la alocación de punteros nulos para todos los objetos
     * -Llama a crear ventana
     * -Llama a crear al jugador
     * -Llama a crear al mapa
     * -Llama a crear al enemigo
     * @param
     * @return void
     */
    this->initVariables();
    this->initWindow();
    this->initPlayer();
    this->initMap();
    this->initEnemies();
}

Game::~Game()
{
    /**
     * -Destructor que libera el espacio en memoria donde se alocan todos los 
     * objetos
     * @param
     * @return void
     */
    delete this->map;
    delete this->player;
    delete this->window;
    delete this->enemy;
}
//Funciones privadas
const bool Game::getWindowIsOpen() const
{
    /**
     * -Devuelve si la ventana se encuentra abierta
     * 
     * @param
     * @return const bool
     */
    return this->window->isOpen();
}

void Game::initVariables()
{
    /**
     * -Crea punteros nulos para los objetos
     * @param
     * @return void
     */
    this->player = nullptr;
    this->enemy = nullptr;
    this->map = nullptr;
    this->window = nullptr;
}

void Game::initWindow()
{
    /**
     * -Crea la ventana con parámetros de alto, ancho, nombre y taza de 
     * fotogramas
     * @param
     * @return void
     */
    this->videoMode.height = 704;
    this->videoMode.width = 704;
    this->window = new sf::RenderWindow(this->videoMode, 
                     "Lame ghost game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);    
}

void Game::initPlayer()
{
    /**
     * -Donde se crea al jugador, se asigna su textura y parámetros iniciales
     * @param
     * @return void
     */
    this->player = new Player("assets/textures/player.png",
                           sf::Vector2f(16.f,20.f),4,sf::Vector2f(324,320),7.f);
}

void Game::initMap()
{
    /**
     * -Crea el mapa con rutas a la textura y al mapa de paredes
     * @param
     * @return void
     */
    this->map = new Map("assets/textures/mansion.png",
                        "assets/textures/mansion.png");
}

void Game::initEnemies()
{
    /**
     * -Crea al enemigo dándole textura y valores de poscición aleatorios
     * @param
     * @return void
     */
    enemy = new Enemy("assets/textures/phantom.png",sf::Vector2f(16.f,16.f),4,
                                   sf::Vector2f(rand()%780+1,rand()%780+1),4.f);
}

void Game::pollEvents()
{
    /**
     * -Cierra la ventana cuando recibe el evento de cerrarla
     * -Espera la input de escape para cerrar la ventana
     * @param
     * @return void
     */
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
    /**
     * -Se encarga de la lógica para encontrar al jugador y buscar si se está
     * en contacto con este
     * @param
     * @return void
     */
    this->enemy->findPlayer();
    if(this->checkCollision(*player,*enemy))
    {
        std::cout<<"Muerteeeeeeee!!!\n";
        this->window->close(); // Cierra la ventana al morir
    }
        
}

void Game::onUpdate()
{
    /**
     * -Recibe input del usuario para cerrar la ventana y mover al jugador
     * -Actualiza estado de enemigos, mapa y jugador
     * @param
     * @return void
     */

    this->pollEvents();
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

    this->updateEnemies();
    this->map->update(*player,*enemy);
    this->player->update();
}

void Game::onRender()
{
    /**
     * -Limpiar frame previo 
     * -Renderizar objetos mapa, jugador y enemigo
     * -Mostrar frame en la ventana
     * @param
     * @return void
     */
    this->window->clear();
    this->map->render(*this->window);
    this->player->render(*this->window);
    this->enemy->render(*this->window);
    this->window->display();
}
bool Game::checkCollision(Player& entity,Entity& colide)
{
    /**
     * -Sobrecarga de checkCollision que descompone al jugador para convertirlo
     * en vectores de líneas verticales y horizontales, para después buscar si
     * este choca con la entidad dada.
     * 
     * @param Player& entity,Entity& colide
     * @return bool
     */

    Line auxLine; // Línea auxiliar para guardar en los vectores
    std::vector<Line> roofs; 
    std::vector<Line> walls;
    roofs.reserve(2); // Reservas para no copiar los vectores
    walls.reserve(2);

    /**
     * Para crear la línea se toma el punto de la esquina superior izquierda
     * y se le suma los largos en x y y para llegar a los demás puntos.
     * posteriormente se guardan en la estructura auxiliar.
     */
    auxLine.pointA = sf::Vector2i(entity.getLocation());
    auxLine.pointB = sf::Vector2i(entity.getLocation().x+entity.getSize().x,
                                                        entity.getLocation().y);

    roofs.emplace_back(auxLine);
    
    auxLine.pointA = sf::Vector2i(entity.getLocation().x,
                                     entity.getLocation().y+entity.getSize().y);
    auxLine.pointB = sf::Vector2i(entity.getLocation().x+entity.getSize().x,
                                     entity.getLocation().y+entity.getSize().y);

    roofs.emplace_back(auxLine);

    auxLine.pointA = sf::Vector2i(entity.getLocation());
    auxLine.pointB = sf::Vector2i(entity.getLocation().x,
                                     entity.getLocation().y+entity.getSize().y);

    walls.emplace_back(auxLine);

    auxLine.pointA = sf::Vector2i(entity.getLocation().x+entity.getSize().x,
                                                        entity.getLocation().y);
    auxLine.pointB = sf::Vector2i(entity.getLocation().x+entity.getSize().x,
                                        entity.getCoord().y+entity.getSize().y);

    walls.emplace_back(auxLine);

    // Llamada a la función de colisiones con la firma requerida y sin afectar 
    // el movimiento del jugador
    return checkCollision(colide,roofs,walls,false);
}
bool Game::checkCollision(Entity& entity,const std::vector<Line>& roofs,
                                const std::vector<Line>& walls,bool move)
{
    /**
     * -Toma una entidad y dos vectores de líneas verticales y horizontales
     * para realizar la comparación de que estos estén en colisión.
     * -Regresa true si se encuentra una colisión
     * -Recibe un booleano para activar el modo de mover la entidad en el caso
     * de que haya colisiones
     * 
     * @param Entity& entity,const std::vector<Line>& roofs,
     *              const std::vector<Line>& walls,bool move
     * @return bool
     */

    bool colide = false; 
    for(int i = 0; i < walls.size(); i++)
    {
        // Comparación de la entidad con paredes verticales
        if(entity.getCoord().x<walls[i].pointA.x && 
        entity.getCoord().x + entity.getSize().x > walls[i].pointA.x &&
        entity.getCoord().y < walls[i].pointB.y &&
        entity.getCoord().y + entity.getSize().y > walls[i].pointA.y)
        {   
            colide = true;
            if(move)
            {
                switch (entity.getDirection())
                {
                    case 'l':
                        // Mueve entidad a la izquierda
                        entity.setCoordX(walls[i].pointA.x); 
                        break;
                    case 'r':
                        // Mueve entidad a la derecha
                        entity.setCoordX(walls[i].pointA.x-entity.getSize().x);
                        break;
                }
            }
        }   
    }
    // Comparación de la entidad con techos y pisos
    for(int i = 0; i < roofs.size(); i++)
    {
        if(entity.getCoord().y<roofs[i].pointA.y &&
        entity.getCoord().y+entity.getSize().y>roofs[i].pointA.y &&
        entity.getCoord().x < roofs[i].pointB.x &&
        entity.getCoord().x + entity.getSize().x>roofs[i].pointA.x)
        {
            colide = true;
            if(move)
            {
                switch (entity.getDirection())
                {
                    case 'u':
                        // Mueve entidad arriba
                        entity.setCoordY(roofs[i].pointA.y);
                        break;
                    case 'd':
                        // Mueve entidad abajo
                        entity.setCoordY(roofs[i].pointA.y-entity.getSize().y);
                        break;
                }
            }
        }
    }
    return colide;
}
