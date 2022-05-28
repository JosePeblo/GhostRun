#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Map
{
private:
    sf::Sprite background;
    sf::Sprite foreground;
    sf::Texture texture;
    sf::Image walls;
public:
    Map();
    Map(std::string);
    ~Map();

    sf::Sprite get();
    void initTexture();
    void initSprite();
};

Map::Map()
{
}
Map::Map()
{
}
Map::~Map()
{
}


#endif