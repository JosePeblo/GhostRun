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
    Map(Player&,std::string,std::string);
    ~Map();
    sf::Sprite get();
    void update();
    void render(sf::RenderTarget&);
    void checkCollision();
private:
    sf::Sprite background;
    sf::Texture texture;
    sf::Image wallMap;
    sf::Vector2f positon;
    std::vector<Line> walls;
    std::vector<Line> roofs;
    Player* player;
    void initTexture();
    void initSprite();
    void initLines();
};

#endif