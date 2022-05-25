#ifndef Player_H
#define Player_H

#include <Entity.h>
#include <iostream>

class Player: public Entity
{
    private:
    sf::IntRect hitbox;

    public:
    Player(std::string,sf::Vector2f,int);
    Player(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Player();
    sf::Sprite get();
    void initTexture();
    void initSprite();
    
    
};

Player::Player(std::string path_,sf::Vector2f size_,int scale_): Entity(path_,size_,scale_)
{

}

Player::Player(std::string path_,sf::Vector2f size_,int scale_,sf::Vector2f coord_)
                                                    : Entity(path_,size_,scale_,coord_)
{
    
    
}
Player::~Player()
{

}
sf::Sprite Player::get()
{
    return Entity::get();
}

#endif