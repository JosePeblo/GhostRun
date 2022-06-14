#ifndef Player_H
#define Player_H

#include <Entity.h>
#include <iostream>

class Player: public Entity
{
    private:
        sf::Vector2f fov = {320,320};

    public:
        Player(std::string,sf::Vector2f,int,int,float);
        Player(std::string,sf::Vector2f,int,sf::Vector2f,int,float);
        ~Player();

        void move(char);
        void update();
        sf::Vector2f getFov();
};

#endif