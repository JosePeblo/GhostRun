#include <Enemy.h>

Enemy::Enemy(std::string path_, sf::Vector2f size_, int scale_,sf::Vector2f coord_): Entity(path_,size_,scale_,coord_)
{
}

Enemy::~Enemy()
{
}
void Enemy::move(char direction_)
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
}
