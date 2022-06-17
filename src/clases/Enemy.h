/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * La clase Enemy hereda los atributos de Entity y se encarga de su movimento, 
 * este dempende de la localización del jugador para que este elemneto 
 * lo siga.
 */
#ifndef ENEMY_H
#define ENEMY_H

// Librerías de SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <Entity.h>
#include <Player.h>
class Enemy: public Entity
{
private:
    float distance(float,float);
public:
    Enemy(std::string,sf::Vector2f,int,sf::Vector2f,float);
    ~Enemy(){};
    void findPlayer();
    void update();
    void move(char);
    void addCoord(float,float);
};

#endif