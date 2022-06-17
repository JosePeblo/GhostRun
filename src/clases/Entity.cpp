#include <Entity.h>

Entity::Entity(std::string path_, sf::Vector2f size_, int scale_)
{
    /**
     * -Constructor para asignar una entidad sin coordenadas iniciales
     * @param std::string path_, sf::Vector2f size_, int scale_
     * @return void
     */
    path = path_;
    size = size_;
    scale = scale_;
    coord = sf::Vector2f(0.f,0.f);
    this->initEntity();
}

Entity::Entity(std::string path_, sf::Vector2f size_, int scale_,
                                                            sf::Vector2f coord_)
{
    /**
     * -Constructor para asignar una entidad con coordenadas iniciales
     * @param sstd::string path_, sf::Vector2f size_, int scale_,
     *                                          sf::Vector2f coord_
     * @return void
     */
    path = path_;
    size = size_;
    scale = scale_;
    coord = coord_;
    this->initEntity();
}

void Entity::setScale(float scale_)
{
    /**
     * -Setter para la escala
     * @param float scale_
     * @return void
     */
    this->sprite.setScale(sf::Vector2f(scale_,scale_));
}

sf::Vector2f Entity::getCoord()
{
    /**
     * -Getter de las coordenadas en el mapa
     * @param 
     * @return sf::Vector2f
     */
    return coord;
}

void Entity::update()
{
    /**
     * -Llama a la animación y actualiza la posición de la entidad
     * -Es necesario llamarla para ver cambios después de modificar la 
     * posición
     * @param 
     * @return void 
     */
    this->animation();
    this->sprite.setPosition(coord);
    this->moving = false;
}

void Entity::render(sf::RenderTarget& target)
{
    /**
     * -Recibe un objeto de sfml para renderizar el sprite en la ventana.
     * @param sf::RenderTarget& target
     * @return void
     */
    target.draw(this->sprite);
}

sf::Vector2f Entity::getSize()
{
    /**
     * -Devuelve el tamaño de la entidad en una estructura de dos valores x,y
     * @param 
     * @return sf::Vector2
     */
    return sf::Vector2f(size.x*scale,size.y*scale);
}

void Entity::setCoord(float x_pos,float y_pos)
{
    /**
     * -Cambia la coordenada de la entidad
     * @param float x_pos,float y_pos
     * @return void
     */
    this->coord.x = x_pos;
    this->coord.y = y_pos;
}

void Entity::setCoordX(float x_pos)
{
    /**
     * -Cambia la coordenada en x de la entidad
     * @param float x_pos
     * @return void
     */
    this->coord.x = x_pos;
}

void Entity::setCoordY(float y_pos)
{
    /**
     * -Cambia la coordenada en y de la entidad
     * @param float y_pos
     * @return void
     */
    this->coord.y = y_pos;
}

void Entity::initEntity()
{
    /**
     * -Inicializa los aspectos gráficos de la entidad, como su rectángulo,
     * textura y posición
     * @param 
     * @return void
     */
    this->sprite.setPosition(coord);
    if(!this->texture.loadFromFile(path))
    {
        std::cout<<"No se pudo cargar la textura\n";
    }
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(0,0),
                                                           sf::Vector2i(size)));
    this->sprite.scale(scale,scale);
}

void Entity::animation()
{
    /**
     * -Cambia el frame de animación cuando la entidad se mueve para que se 
     * ciclen los frames del atlas de texturas
     * @param 
     * @return void
     */
    if(moving)
    {
        this->currentFrame += 16;
        this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(currentFrame,0),
                                                           sf::Vector2i(size)));
        if(currentFrame>=48)
            currentFrame = 0;
    }
    else
    {
        currentFrame = 0;
        this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(currentFrame,0),
                                                           sf::Vector2i(size)));

    }
}

char Entity::getDirection()
{
    /**
     * -Regresa un caracter que indica dirección  
     * Arriba 'u'
     * Abajo 'd'
     * Izquierda 'l'
     * Derecha 'r'
     * @param 
     * @return char
     */
    return direction;
}

void Entity::setDirection(char direction_)
{
    /**
     * -Recibe un caracter que indica dirección 
     * Arriba 'u'
     * Abajo 'd'
     * Izquierda 'l'
     * Derecha 'r'
     * @param char direction_
     * @return void
     */
    direction = direction_;
}

bool Entity::getIsMoving()
{
    /**
     * -Regresa true si la entidad se entá moviendo
     * 
     * @param 
     * @return bool
     */
    return moving;
}

void Entity::setIsMoving(bool isMoving_)
{
    /**
     * -Cambia el parámetro del movimiento de la entidad
     * @param bool isMoving_
     * @return void
     */
    moving = isMoving_;
}

void Entity::setSpeed(float speed_)
{
    /**
     * -Cambia el parámetro de la velocidad de la entidad
     * @param bool ifloat speed_
     * @return void
     */
    speed = speed_;
}

float Entity::getSpeed()
{
    /**
     * -Regresa el valor de velocidad de la entidad
     * 
     * @param 
     * @return float
     */
    return speed;
}
