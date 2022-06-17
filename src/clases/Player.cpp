#include <Player.h>

Player::Player(std::string path_,sf::Vector2f size_,int scale_,float speed): Entity(path_,size_,scale_)
{
    /**
     * -Constructor sin coordenadas
     * -Recibe ruta a la textura, tamaño, escala y velocidad
     * @param std::string path_,sf::Vector2f size_,int scale_,float speed
     * @return void
     */
    this->setSpeed(speed);
}

Player::Player(std::string path_,sf::Vector2f size_,int scale_,
             sf::Vector2f coord_,float speed): Entity(path_,size_,scale_,coord_)
{  
    /**
     * -Constructor con coordenadas
     * -Recibe ruta a la textura, tamaño, escala, coordenada y velocidad
     * @param std::string path_,sf::Vector2f size_,int scale_,
     *                                          sf::Vector2f coord_,float speed
     * @return void
     */
    location = coord_;
    this->setSpeed(speed);
}

sf::Vector2f Player::getFov()
{
    /**
     * -Regresa el campo de visión del jugador
     * @param
     * @return sf::Vector2f
     */
    return fov;
}
sf::Vector2f Player::getLocation()
{
    /**
     * -Regresa la localización, valor distintio a la coordenada que representa
     * su poscición relativa a la ventana
     * @param
     * @return sf::Vector2f
     */
    return location;
}

void Player::update()
{
    /**
     * -Llama a la animación y actualiza el valor de movimiento
     * @param
     * @return void
     */
    this->animation();
    this->moving = false;
}

void Player::move(char direction_)
{
    /**
     * -Cambia las coordenadas del jugador basándose en la input de dirección
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
    
}
