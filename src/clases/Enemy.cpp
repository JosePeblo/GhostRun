#include <Enemy.h>

Enemy::Enemy(std::string path_, sf::Vector2f size_, int scale_,
             sf::Vector2f coord_,float speed): Entity(path_,size_,scale_,coord_)
{
    /**
     * -Constructor 
     * -Recibe ruta a la textura, tamaño, escala coordenadas y velocidad
     * @param std::string path_, sf::Vector2f size_, int scale_,
     *                                          sf::Vector2f coord_,float speed
     * @return void
     */
    this->setSpeed(speed);
}

void Enemy::update()
{
    /**
     * -Llama a la animación y actualiza el valor de movimiento
     * @param
     * @return void
     */
    this->animation();
    this->sprite.setPosition(coord);
    this->moving = false;
}

void Enemy::findPlayer()
{
    /**
     * -Busca llegar al centro de la pantalla, donde está el jugador buscando 
     * que dirección le da una distancia menor
     * @param
     * @return void
     */
    sf::Vector2f pastCoord = this->getCoord(); // Obtiene coordenada actual
    sf::Vector2f newCoord = pastCoord; // Crea una nueva igual a la anterior
    newCoord.x += this->getSpeed(); // Se le opera el valor de velocidad
    // Se compara si la distancia es menor entre las coordenadas
    if(this->distance(320,newCoord.x) < this->distance(320,pastCoord.x))
    {
        // Se asiga una dirección de movimiento
        this->move('r');
    }
    newCoord = pastCoord;
    newCoord.x -= this->getSpeed();
    if(this->distance(320,newCoord.x) < this->distance(320,pastCoord.x))
    {
        this->move('l');
    }
    newCoord = pastCoord;   
    newCoord.y += this->getSpeed();
    if(this->distance(320,newCoord.y) < this->distance(320,pastCoord.y))
    {
        this->move('d');
    }
    newCoord = pastCoord;
    newCoord.y -= this->getSpeed();
    if(this->distance(320,newCoord.y) < this->distance(320,pastCoord.y))
    {
        this->move('u');
    }
}
void Enemy::move(char direction_)
{
    /**
     * -Cambia las coordenadas del enemigo basándose en la input de dirección
     * y la velocidad de este
     * 
     * @param char direction_
     * @return void
     */
    switch (direction_)
    {
    case 'u':
        this->setCoordY(this->getCoord().y-this->getSpeed());
    break;
    case 'd':
        this->setCoordY(this->getCoord().y+this->getSpeed());
    break;
    case 'l':
        this->setCoordX(this->getCoord().x-this->getSpeed());
    break;
    case 'r':
        this->setCoordX(this->getCoord().x+this->getSpeed());
    break;
    }
    this->setIsMoving(true);
    this->setDirection(direction_);
    this->update();
}

float Enemy::distance(float end, float begining)
{
    /**
     * -Calcula un valor de distancia que evita las raices cuadradas ya que 
     * solo importa comparar si las distancias entre puntos 
     * son mayores o menores
     * 
     * @param float end, float begining
     * @return float
     */
    return abs(end - begining);
}

void Enemy::addCoord(float x,float y)
{
    /**
     * -Suma las componetntes a la coordenada del enemigo
     * 
     * @param float x,float y
     * @return void
     */
    this->coord.x += x;
    this->coord.y += y;
    this->update();
}