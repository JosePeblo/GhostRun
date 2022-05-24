#ifndef Player_H
#define Player_H

#include <Entity.h>
#include <iostream>

class Player: public Entity
{
    private:
    sf::IntRect hitbox;

    public:
    Player(float,float,float,std::string);
    ~Player();
    sf::Sprite get();
    void initTexture();
    void initSprite();
    
    
};
Player::Player(float xpos,float ypos,float size,std::string texture)
                                            : Entity(xpos,ypos,size,texture)
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