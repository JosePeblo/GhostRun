/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * La clase Player hereda los atributos de Entity y se encarga de su movimento
 * y localización 
 */
#ifndef Player_H
#define Player_H

// Librerías de SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


#include <Entity.h>
#include <iostream>

class Player: public Entity
{
    private:
        // Atributos privados
        sf::Vector2f fov = {320,320};
        sf::Vector2f location = {305,305};
    public:
        // Constructores y destructor
        Player(std::string,sf::Vector2f,int,float);
        Player(std::string,sf::Vector2f,int,sf::Vector2f,float);
        ~Player(){};

        // Métods públicos
        void move(char);
        void update();
        sf::Vector2f getFov();
        sf::Vector2f getLocation();
};

#endif