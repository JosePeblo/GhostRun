#include <Map.h>

Map::Map(std::string mapPath,std::string wallPath)
{
    /**
     * -Constructor que pide la ruta a la imagen del la textura y la de los 
     * muros
     * -Carga Imágenes PNGs 
     * 
     * @param std::string mapPath,std::string wallPath
     * @return void
     */
    this->wallMap.loadFromFile(wallPath);
    this->background.setPosition(sf::Vector2f(0.f,0.f));
    this->background.setScale(sf::Vector2f(4.f,4.f));
    this->texture.loadFromFile(mapPath);
    this->background.setTexture(this->texture);
    this->initLines();
}

void Map::update(Player& player, Enemy& enemy)
{
    /**
     * -Mueve el mapa al contrario de la posición del jugador y desplaza al 
     * enemigo
     * 
     * @param Player& player, Enemy& enemy
     * @return void
     */
    // Usa el Fov del jugador como factor de desface para centrar el mapa
    this->background.setPosition(-(player.getCoord()-player.getFov()));
    if(player.getIsMoving())
    {
        // Mueve el mapa en base al valor de velocidad del jugador
        switch (player.getDirection())
        {
        case 'u':
            enemy.addCoord(0,player.getSpeed());
        break;
        case 'd':
            enemy.addCoord(0,-player.getSpeed());
        break;
        case 'l':
            enemy.addCoord(player.getSpeed(),0);
        break;
        case 'r':
            enemy.addCoord(-player.getSpeed(),0);
        break;
        }
    }
}

void Map::render(sf::RenderTarget& target)
{
    /**
     * -Recibe un objeto de sfml para renderizar el sprite en la ventana.
     * @param sf::RenderTarget& target
     * @return void
     */
    target.draw(this->background);
}

void Map::initLines()
{
    /**
     * -Toma el mapa de muros y busca en todos los pixeles cuando se forman 
     * esquinas para crear líneas y añadirlas a sus vectores correspondientes
     * @param 
     * @return void
     */
    sf::Color colors[2][2]; // Objeto color auxiliar
    int blackPixels = 0; // Contador de pixeles negros
    bool end = false; // Bandera para saber si se termina de crear una línea
    Line auxLine; // Línea auxiliar para guardar valores

    // Busca en cada pixel de la imagen para hallar líneas horizontales
    for(int i = 0; i < wallMap.getSize().y-1; i++) // Filas
    {
        for(int j = 0; j < wallMap.getSize().x-1; j++) // Columnas
        {
            blackPixels = 0; // inica el conteo de pixeles en cero
            /**
             * Creamos una matríz con los colores de el cuadrado que le procede
             * al pixel.
             */
            
            colors[0][0] = wallMap.getPixel(j,i);
            colors[1][0] = wallMap.getPixel(j+1,i);
            colors[0][1] = wallMap.getPixel(j,i+1);
            colors[1][1] = wallMap.getPixel(j+1,i+1);
            // Recorremos la matríz
            for(int k = 0; k<2; k++)
            {
                for(int l = 0; l<2; l++)
                {
                    // Contamos cuantos pixeles son negros
                    if(colors[k][l] == sf::Color::Black)
                        blackPixels++;
                }
            }
            // Si solo hay un pixel negro se pone el punto en este
            if(blackPixels == 1)
            {
                // Se recorre de nuevo la matríz para encontrar el punto
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::Black)
                        {
                            // Definimos si es un punto inicial o final
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((j+k)*4,(i+l)*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+k)*4,(i+l)*4);
                                roofs.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
            // Si solo hay un blanco, la esquina es contraria este
            if(blackPixels == 3)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::White)
                        {
                            if(!end)
                            {
                                /**
                                 * Usamos valor absoluto y una resta de uno
                                 * para encontrar la coordenada inverza
                                 * |0 1|             |1 0|
                                 * |1 0| inverza ->  |0 1|
                                 */
                                auxLine.pointA = sf::Vector2i((j+abs(k-1))*4,
                                                              (i+abs(l-1))*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+abs(k-1))*4,
                                                              (i+abs(l-1))*4);
                                roofs.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
        }
    }
    // Repetimos el proceso para las paredes
    for(int i = 0; i < wallMap.getSize().x-1; i++) 
    {
        for(int j = 0; j < wallMap.getSize().y-1; j++)
        {
            blackPixels = 0;
            colors[0][0] = wallMap.getPixel(i,j);
            colors[1][0] = wallMap.getPixel(i+1,j);
            colors[0][1] = wallMap.getPixel(i,j+1);
            colors[1][1] = wallMap.getPixel(i+1,j+1);
            for(int k = 0; k<2; k++)
            {
                for(int l = 0; l<2; l++)
                {
                    if(colors[k][l] == sf::Color::Black)
                        blackPixels++;
                }
            }
            if(blackPixels == 1)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::Black)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((i+k)*4,(j+l)*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+k)*4,(j+l)*4);
                                walls.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
            if(blackPixels == 3)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::White)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((i+abs(k-1))*4,
                                                              (j+abs(l-1))*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+abs(k-1))*4,
                                                              (j+abs(l-1))*4);
                                walls.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
        }
    }
}

const std::vector<Line> Map::getWalls() const
{
    /**
     * -Regresa el vector de líneas de paredes
     * @param 
     * @return const std::vector<Line>
     */
    return walls;
}
const std::vector<Line> Map::getRoofs() const
{
    /**
     * -Regresa el vector de líneas de techos
     * @param 
     * @return const std::vector<Line>
     */
    return roofs;
}
