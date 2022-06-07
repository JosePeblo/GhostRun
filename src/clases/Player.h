#ifndef Player_H
#define Player_H

#include <Entity.h>
#include <iostream>

class Player: public Entity
{
    private:
    sf::IntRect hitbox;
    float speed = 7.f;

    public:
    Player(std::string,sf::Vector2f,int);
    Player(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Player();
    sf::Sprite get();
    void initTexture();
    void initSprite();
    void move(char);
};

#endif