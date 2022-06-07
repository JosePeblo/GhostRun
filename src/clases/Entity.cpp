#include <Entity.h>

Entity::Entity(std::string path_, sf::Vector2f size_, int scale_)
{
    path = path_;
    size = size_;
    scale = scale_;
    coord = sf::Vector2f(0.f,0.f);
    this->initEntity();
}

Entity::Entity(std::string path_, sf::Vector2f size_, int scale_,sf::Vector2f coord_)
{
    path = path_;
    size = size_;
    scale = scale_;
    coord = coord_;
    this->initEntity();
}

void Entity::setScale(float scale_)
{
    this->sprite.setScale(sf::Vector2f(scale_,scale_));
}

sf::Vector2f Entity::getPos()
{
    return coord;
}

sf::Sprite Entity::get()
{
    return sprite;
}

void Entity::update()
{
    this->animation();
    this->sprite.setPosition(coord);
    this->moving = false;
}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
    
}
sf::Vector2f Entity::getSize()
{
    return sf::Vector2f(size.x*scale,size.y*scale);
}

void Entity::setPosition(float x_pos,float y_pos)
{
    this->coord.x = x_pos;
    this->coord.y = y_pos;
}

void Entity::setPositionX(float x_pos)
{
    this->coord.x = x_pos;
}

void Entity::setPositionY(float y_pos)
{
    this->coord.y = y_pos;
}

void Entity::initEntity()
{
    // Initialize sprite
    this->sprite.setPosition(coord);
    // Initialize texture
    if(!this->texture.loadFromFile(path))
    {
        std::cout<<"No se pudo cargar la textura\n";
    }
    // Initialize sprite
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(size))); // 0,0,16,20
    
    this->sprite.scale(scale,scale);
}

void Entity::animation()
{
    if(moving)
    {
        
        this->currentFrame += 16;
        this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(currentFrame,0),sf::Vector2i(size)));
        if(currentFrame>=48)
            currentFrame = 0;
    }
    else
    {
        currentFrame = 0;
        this->sprite.setTextureRect(sf::IntRect(sf::Vector2i(currentFrame,0),sf::Vector2i(size)));

    }
}

char Entity::getDirection()
{
    return direction;
}

void Entity::setDirection(char direction_)
{
    direction = direction_;
}

bool Entity::getIsMoving()
{
    return moving;
}

void Entity::setIsMoving(bool isMoving_)
{
    moving = isMoving_;
}
