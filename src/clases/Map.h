/**
 * Lame ghost game
 * José Pablo Martínez Valdivia
 * A01275676
 * 17/06/2022
 * 
 * La clase Map inicializa las texturas y renderiza la imagen del mapa, además
 * recibe una imagen en blanco y negro para generar las paredes del nivel
 */
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <cmath>
#include <Enemy.h>
#include <Player.h>

// Librerías de SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

struct Line
{
    // Estructura para asociar dos puntos que representan una línea
    sf::Vector2i pointA, pointB;
};

class Map
{
public:
    // Constructores y destructor
    Map(std::string,std::string);
    ~Map(){}
    // Métodos públicos
    void update(Player&,Enemy&);
    void move(char);
    void render(sf::RenderTarget&);
    const std::vector<Line> getWalls() const;
    const std::vector<Line> getRoofs() const;
private:
    // Atributos privados
    sf::Sprite background;
    sf::Texture texture;
    sf::Image wallMap;
    sf::Vector2f positon;
    std::vector<Line> walls;
    std::vector<Line> roofs;
    // Método privdo
    void initLines();
};

#endif