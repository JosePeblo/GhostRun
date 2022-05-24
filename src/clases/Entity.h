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
    Entity(float,float,float,std::string);
    ~Entity(){};

    void setScale(float);
    sf::Vector2f getPos();
    virtual sf::Sprite get();
    void move(char);
    void update();
    void render(sf::RenderTarget&);

    private:
    sf::Sprite entity;
    sf::Texture texture;
    sf::Vector2f position;
    sf::Vector2f scale;
    std::string textPath;
    void setPosition(float,float);
    void initTexture();
    void initSprite();
};
Entity::Entity()
{
    
}
Entity::Entity(float posX, float posY, float scale_, std::string texturePath)
{
    position.x = posX;
    position.y = posY;
    textPath = texturePath;
    std::cout<<textPath<<"\n";
    scale = sf::Vector2f(scale_,scale_);
    this->entity.setPosition(position);
    this->initTexture();
    this->initSprite();
}
sf::Sprite Entity::get()
{
    return entity;
}
void Entity::setPosition(float x_pos,float y_pos)
{
    this->entity.setPosition(sf::Vector2f(x_pos,y_pos));
}
void Entity::setScale(float scale_)
{
    this->entity.setScale(sf::Vector2f(scale_,scale_));
}
sf::Vector2f Entity::getPos()
{
    return position;
}
void Entity::move(char direction)
{
    switch (direction)
    {
    case 'u':
        position.y += 7.f;
    break;
    case 'd':
        position.y -= 7.f;
    break;
    case 'l':
        position.x += 7.f;
    break;
    case 'r':
        position.x -= 7.f;
    break;
    }
    this->entity.setPosition(position);
}
void Entity::initTexture()
{
    if(!this->texture.loadFromFile(textPath))
    {
        std::cout<<"No se pudo cargar la textura\n";
    }
}
void Entity::initSprite()
{
    this->entity.setTexture(this->texture);
    this->entity.setTextureRect(sf::Rect(0,0,16,20));
    this->entity.scale(4.f,4.f);
}
void Entity::update()
{
}
void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->entity);
}

#endif