#ifndef MAP_H
#define MAP_H

#include <iostream>

#include <vector>
#include <Player.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

struct Line
{
    sf::Vector2f pointA;
    sf::Vector2f pointB;
};

class Map
{
public:
    Map();
    Map(std::string);//,const Player&
    ~Map();
    sf::Sprite get();
    void update();
    void render(sf::RenderTarget&);
private:
    sf::Sprite background;
    sf::Sprite foreground;
    sf::Texture texture;
    sf::Image wallMap;
    sf::Vector2f positon;
    std::vector<Line> lines;
    std::vector<Player*> players;
    void initTexture();
    void initSprite();
    void initLines();
};

Map::Map()
{
}

Map::Map(std::string path) //, const Player& player
{
    this->wallMap.loadFromFile("assets/mapWalls/mapSpiral.png");
    this->background.setPosition(sf::Vector2f(0.f,0.f));
    this->background.setScale(sf::Vector2f(4.f,4.f));
    this->texture.loadFromFile(path);
    this->background.setTexture(this->texture);
}

Map::~Map()
{
}

void Map::update()
{
}

void Map::render(sf::RenderTarget& target)
{
    target.draw(this->background);
}

void Map::initTexture()
{
}

void Map::initSprite()
{
}
void Map::initLines()
{
    lines.push_back({sf::Vector2f(0,0),sf::Vector2f(0,700)});
    // for(int i = 1; i < wallMap.getSize().x; i++)
    // {
    //     for(int j = 1; j < wallMap.getSize().y; j++)
    //     {
    //         if(wallMap.getPixel(j,i) == sf::Color::Black){}
    //             //std::cout<<'#';
    //         //else
    //             //std::cout<<' ';
    //     }
    //     //std::cout<<'\n';
    // }
}

#endif