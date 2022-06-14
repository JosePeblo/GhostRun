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
    virtual void update();
    void render(sf::RenderTarget&);
    void setScale(float);
    void setPosition(float,float);
    void setPositionX(float);
    void setPositionY(float);
    void setDirection(char);
    void setIsMoving(bool);
    void setSpeed(float);
    void setLife(int);
    int getLife();
    float getSpeed();
    char getDirection();
    bool getIsMoving();
    sf::Vector2f getPos();
    sf::Vector2f getSize();
    
    private:
    int life;
    float speed;
    int scale;
    int currentFrame = 0;
    char direction;
    sf::Vector2f size;
    sf::Vector2f coord;
    sf::Texture texture;
    sf::Sprite sprite;
    std::string path;

    void initEntity();

    protected:
    
    void animation();
    bool moving = false;
};

#endif