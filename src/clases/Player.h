#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Player
{
    private:
    sf::RectangleShape hitbox;
    float xPos;
    float yPos;

    public: 
    Player();
    //Player(float,float,float);
    ~Player();

    void setPos(float,float);
    void setSize(float);
    sf::RectangleShape getPlayer();
};
Player::Player()
{

}
//Player::Player(float x_pos, float y_pos, float size)
//{
  //  xPos = x_pos;
//    yPos = y_pos;
//    this->hitbox.setPosition(sf::Vector2f(x_pos,y_pos));
//    this->hitbox.setSize(sf::Vector2f(size,size));
//    this->hitbox.setFillColor(sf::Color::Cyan);
//}
Player::~Player()
{
    //delete thisplayer;
}
sf::RectangleShape Player::getPlayer()
{
    return hitbox;
}
void Player::setPos(float posx,float posy)
{
    this->hitbox.setPosition(sf::Vector2f(posx,posy));
}
void Player::setSize(float size)
{
    this->hitbox.setSize(sf::Vector2f(size,size));
    this->hitbox.setFillColor(sf::Color::Cyan);
}


#endif