#ifndef Entity_H
#define Entity_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class Entity
{
    public: 
    Entity(){};
    Entity(std::string,sf::Vector2f,int),
    Entity(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Entity(){};

    virtual void move(char) = 0;
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
    void setDirection(char);
    bool getIsMoving();
    void setIsMoving(bool);

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

#endif