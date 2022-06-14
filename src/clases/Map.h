/**
 * @file Map.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <cmath>
#include <Enemy.h>
#include <Player.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

struct Line
{
    sf::Vector2i pointA, pointB;
};

class Map
{
public:
    Map();
    Map(std::string,std::string);
    ~Map(){}
    void update(Player&);
    void move(char);
    void render(sf::RenderTarget&);
    const std::vector<Line> getWalls() const;
    const std::vector<Line> getRoofs() const;
private:
    sf::Sprite background;
    sf::Texture texture;
    sf::Image wallMap;
    sf::Vector2f positon;
    std::vector<Line> walls;
    std::vector<Line> roofs;
    void initLines();
};

#endif