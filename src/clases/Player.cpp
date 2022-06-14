#include <Player.h>

Player::Player(std::string path_,sf::Vector2f size_,int scale_,int life,float speed): Entity(path_,size_,scale_)
{
    this->setLife(life);
    this->setSpeed(speed);
}

Player::Player(std::string path_,sf::Vector2f size_,int scale_,sf::Vector2f coord_,int life,float speed)
                                                    : Entity(path_,size_,scale_,coord_)
{  
    this->setLife(life);
    this->setSpeed(speed);
}
Player::~Player()
{
}

sf::Vector2f Player::getFov()
{
    return fov;
}

void Player::update()
{
    this->animation();
    this->moving = false;
}

void Player::move(char direction_)
{
    switch (direction_)
    {
    case 'u':
        this->setPositionY(this->getPos().y-this->getSpeed());
    break;
    case 'd':
        this->setPositionY(this->getPos().y+this->getSpeed());
    break;
    case 'l':
        this->setPositionX(this->getPos().x-this->getSpeed());
    break;
    case 'r':
        this->setPositionX(this->getPos().x+this->getSpeed());
    break;
    }
    this->setIsMoving(true);
    this->setDirection(direction_);
    
}
