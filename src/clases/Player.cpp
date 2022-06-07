#include <Player.h>

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
void Player::move(char direction_)
{

    switch (direction_)
    {
    case 'u':
        this->setPositionY(this->getPos().y-speed);
    break;
    case 'd':
        this->setPositionY(this->getPos().y+speed);
    break;
    case 'l':
        this->setPositionX(this->getPos().x-speed);
    break;
    case 'r':
        this->setPositionX(this->getPos().x+speed);
    break;
    }
    this->setIsMoving(true);
    this->setDirection(direction_);
}
