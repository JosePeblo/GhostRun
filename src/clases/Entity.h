/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * La clase Entity sirve de molde para crear entidades rectangulares con 
 * texturas.
 * Del mismo modo se encarga de la animación de estas entidades por medio de 
 * mapas de texturas y renderiza estas en la pantalla.
 */
#ifndef Entity_H
#define Entity_H

// Librerías de SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

class Entity
{
    public: 
    // Constructores y destructor
    Entity(){};
    Entity(std::string,sf::Vector2f,int),
    Entity(std::string,sf::Vector2f,int,sf::Vector2f);
    ~Entity(){};

    // Métodos virtuales
    virtual void move(char) = 0; // Interfás del método mover
    virtual void update();

    // Métodos públicos
    void render(sf::RenderTarget&);
    void setScale(float);
    void setCoord(float,float);
    void setCoordX(float);
    void setCoordY(float);
    void setDirection(char);
    void setIsMoving(bool);
    void setSpeed(float);
    void setLife(int);
    int getLife();
    float getSpeed();
    char getDirection();
    bool getIsMoving();
    sf::Vector2f getCoord();
    sf::Vector2f getSize();
    
    private:
    // Atributos privados
    float speed;
    int scale;
    int currentFrame = 0;
    char direction;
    sf::Vector2f size;
    sf::Texture texture;
    std::string path;
    // Método privado
    void initEntity();

    protected:
    // Atrubutos protegidos
    sf::Vector2f coord;
    sf::Sprite sprite;
    bool moving = false;
    // Método protegido
    void animation();
};

#endif