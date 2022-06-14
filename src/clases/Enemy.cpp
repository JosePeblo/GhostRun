#include <Enemy.h>

Enemy::Enemy(std::string path_, sf::Vector2f size_, int scale_,sf::Vector2f coord_,int life,float speed): Entity(path_,size_,scale_,coord_)
{
    this->setLife(life);
    this->setSpeed(speed);
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
    Entity::update();
}

void Enemy::findPlayer(Player& player_)
{
    sf::Vector2f pastCoord = this->getPos();
    sf::Vector2f newCoord = pastCoord;
    newCoord.x += this->getSpeed();
    if(this->distance(player_.getPos().x,newCoord.x) < this->distance(player_.getPos().x,pastCoord.x))
    {
        this->move('r');
    }
    newCoord = pastCoord;
    newCoord.x -= this->getSpeed();
    if(this->distance(player_.getPos().x,newCoord.x) < this->distance(player_.getPos().x,pastCoord.x))
    {
        this->move('l');
    }

    newCoord = pastCoord;   
    newCoord.y += this->getSpeed();
    if(this->distance(player_.getPos().y,newCoord.y) < this->distance(player_.getPos().y,pastCoord.y))
    {
        this->move('d');
    }
    newCoord = pastCoord;
    newCoord.y -= this->getSpeed();
    if(this->distance(player_.getPos().y,newCoord.y) < this->distance(player_.getPos().y,pastCoord.y))
    {
        this->move('u');
    }
}
void Enemy::move(char direction_)
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
    this->update();
}

float Enemy::distance(float end, float begining)
{
    return abs(end - begining);
}
