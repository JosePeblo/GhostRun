#ifndef ENEMY_H
#define ENEMY_H

#include <Entity.h>
#include <Player.h>
class Enemy: public Entity
{
private:
    bool inFocus;
    float distance(float,float);
public:
    Enemy(std::string,sf::Vector2f,int,sf::Vector2f,int,float);
    ~Enemy();
    void findPlayer(Player&);
    void update();
    void move(char);
};

#endif