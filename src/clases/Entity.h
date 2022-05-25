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
    Entity();
    Entity(std::string,sf::Vector2f,int),
    Entity(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Entity(){};

    void move(char);
    void setCoord(sf::Vector2f);

    void setScale(float);
    sf::Vector2f getPos();
    virtual sf::Sprite get();
    void update();
    void render(sf::RenderTarget&);

    private:
    std::string path;
    sf::Vector2f size;
    int scale;
    sf::Vector2f coord;
    sf::Sprite sprite;
    sf::Texture texture;
    void setPosition(float,float);
    void initEntity();
};
Entity::Entity()
{
    
}
Entity::Entity(std::string path_, sf::Vector2f size_, int scale_)
{
    path = path_;
    size = size_;
    scale = scale_;
    coord = sf::Vector2f(1.f,1.f);
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
sf::Sprite Entity::get()
{
    return sprite;
}
void Entity::setPosition(float x_pos,float y_pos)
{
    this->sprite.setPosition(sf::Vector2f(x_pos,y_pos));
}
void Entity::setScale(float scale_)
{
    this->sprite.setScale(sf::Vector2f(scale_,scale_));
}
sf::Vector2f Entity::getPos()
{
    return coord;
}
void Entity::move(char direction)
{
    switch (direction)
    {
    case 'u':
        coord.y += 7.f;
    break;
    case 'd':
        coord.y -= 7.f;
    break;
    case 'l':
        coord.x += 7.f;
    break;
    case 'r':
        coord.x -= 7.f;
    break;
    }
    this->sprite.setPosition(coord);
}
void Entity::initEntity()
{
    std::cout<<"hola mundo\n";
    // Initialize sprite
    this->sprite.setPosition(coord);
    // Initialize texture
    if(!this->texture.loadFromFile(path))
    {
        std::cout<<"No se pudo cargar la textura\n";
    }
    // Initialize sprite
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(sf::Rect(sf::Vector2i(0,0),sf::Vector2i(size))); // 0,0,16,20
    
    this->sprite.scale(scale,scale);
}
void Entity::update()
{
}
void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->sprite);
}

#endif