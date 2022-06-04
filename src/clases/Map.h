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
    sf::Vector2f pointA, pointB;
};

class Map
{
public:
    Map();
    Map(Player&,std::string,std::string);//,const Player&
    ~Map();
    sf::Sprite get();
    void update();
    void render(sf::RenderTarget&);
    void checkCollision();
private:
    sf::Sprite background;
    //sf::Sprite foreground;
    sf::Texture texture;
    sf::Image wallMap;
    sf::Vector2f positon;
    std::vector<Line> walls;
    std::vector<Line> ceilings;
    Player* player;
    void initTexture();
    void initSprite();
    void initLines();
};

Map::Map()
{
}

Map::Map(Player& player_,std::string mapPath,std::string wallPath)
{
    player = &player_;
    this->wallMap.loadFromFile(wallPath);
    this->background.setPosition(sf::Vector2f(0.f,0.f));
    this->background.setScale(sf::Vector2f(4.f,4.f));
    this->texture.loadFromFile(mapPath);
    this->background.setTexture(this->texture);
    this->initLines();
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

    int blackPixels;
    
    Line testWall;
    testWall.pointA = sf::Vector2f(64,64);
    testWall.pointB = sf::Vector2f(64,640);
    walls.push_back(testWall);
    ceilings.push_back(testWall);
    /*
    walls.push_back({sf::Vector2f(64,64),sf::Vector2f(64,640)});
    walls.push_back({sf::Vector2f(640,64),sf::Vector2f(640,640)});
    ceilings.push_back({sf::Vector2f(64,64),sf::Vector2f(640,64)});
    ceilings.push_back({sf::Vector2f(64,640),sf::Vector2f(640,640)});*/
    
    for(int i = 1; i < wallMap.getSize().x; i++)
    {
        for(int j = 1; j < wallMap.getSize().y; j++)
        {
            /*
            if(wallMap.getPixel(j,i) == sf::Color::Black)
                std::cout<<'#';
            else
                std::cout<<' ';
            blackPixels = 0;
            */
            for(int k = 0; k<2;k++)
            {
                for(int l = 0; l<2;l++)
                {
                    if(wallMap.getPixel(j+k,i+l) == sf::Color::Black)
                        blackPixels++;
                }
            }
            if(blackPixels == 1)
                std::cout<<blackPixels<<'\n';
        }
        //std::cout<<'\n';
    }
    /*wallMap.getPixel(j,i) == sf::Color::Black &&
            wallMap.getPixel(j+1,i) == sf::Color::Black &&
            wallMap.getPixel(j,i+1) == sf::Color::Black &&
            wallMap.getPixel(j+1,i+1) == sf::Color::White*/
}
void Map::checkCollision()
{
    for(int i = 0; i<2; i++)
    {
        // For vertical walls
        if(player->getPos().x<walls[i].pointA.x && 
        player->getPos().x + player->getSize().x > walls[i].pointA.x &&
        player->getPos().y < walls[i].pointB.y &&
        player->getPos().y + player->getSize().y > walls[i].pointA.y)
        {   
            switch (player->getDirection())
            {
                case 'l':
                    player->setPositionX(walls[i].pointA.x);
                    break;
                case 'r':
                    player->setPositionX(walls[i].pointA.x-(player->getSize().x));
                    break;
            }
        }   
    }
    for(int i = 0; i<2; i++)
    {
        if(player->getPos().y<ceilings[i].pointA.y &&
        player->getPos().y+player->getSize().y>ceilings[i].pointA.y &&
        player->getPos().x < ceilings[i].pointB.x &&
        player->getPos().x + player->getSize().x>ceilings[i].pointA.x)
        {
            switch (player->getDirection())
            {
                case 'u':
                    player->setPositionY(ceilings[i].pointA.y);
                    break;
                case 'd':
                    player->setPositionY(ceilings[i].pointA.y-(player->getSize().y));
                    break;
            }
        }
    }
}

#endif