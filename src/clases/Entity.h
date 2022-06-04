#ifndef Entity_H
#define Entity_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class Entity
{
    public: 
    Entity(){};
    Entity(std::string,sf::Vector2f,int),
    Entity(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Entity(){};

    void move(char);
    //void setCoord(sf::Vector2f);

    void setScale(float);
    sf::Vector2f getPos();
    virtual sf::Sprite get();
    void update();
    void render(sf::RenderTarget&);
    sf::Vector2f getSize();
    void setPosition(float,float);
    void setPositionX(float);
    void setPositionY(float);
    char getDirection();

    private:
    std::string path;
    sf::Vector2f size;
    int scale;
    sf::Vector2f coord;
    sf::Sprite sprite;
    sf::Texture texture;
    bool moving = false;
    int currentFrame = 0;
    char direction;
    void initEntity();
    void animation();
};

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

void Entity::move(char direction_)
{
    switch (direction_)
    {
    case 'u':
        coord.y -= 7.f;
    break;
    case 'd':
        coord.y += 7.f;
    break;
    case 'l':
        coord.x -= 7.f;
    break;
    case 'r':
        coord.x += 7.f;
    break;
    }
    moving = true;
    direction = direction_;
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
#endif