#ifndef ENEMY_H
#define ENEMY_H

#include <Entity.h>
class Enemy: public Entity
{
private:
    float speed = 5.f;
public:
    Enemy(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Enemy();
    void move(char);
};

#endif