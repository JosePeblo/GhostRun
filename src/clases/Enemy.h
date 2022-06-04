#ifndef ENEMY_H
#define ENEMY_H

#include <Entity.h>
class Enemy: public Entity
{
private:
    float speed = 5.f;
public:
    Enemy(/* args */);
    ~Enemy();
    void Enemy::move(char);
};

Enemy::Enemy(/* args */)
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








#endif