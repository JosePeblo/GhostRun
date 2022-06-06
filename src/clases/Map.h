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
    
    sf::Color colors[2][2];
    int blackPixels = 0;
    bool end = false;
    Line auxLine;
    /*
    auxLine.pointA = sf::Vector2i(0,0);
    auxLine.pointB = sf::Vector2i(0,640);
    walls.push_back(auxLine);
    auxLine.pointA = sf::Vector2i(640,64);
    auxLine.pointB = sf::Vector2i(640,640);
    walls.push_back(auxLine);
    */
    //ceilings.push_back(auxLine);
    /*
    walls.push_back({sf::Vector2f(64,64),sf::Vector2f(64,640)});
    walls.push_back({sf::Vector2f(640,64),sf::Vector2f(640,640)});
    ceilings.push_back({sf::Vector2f(64,64),sf::Vector2f(640,64)});
    ceilings.push_back({sf::Vector2f(64,640),sf::Vector2f(640,640)});
    */
    //std::cout<<wallMap.getSize().x;

    // For ceilings
    for(int i = 0; i < wallMap.getSize().y-1; i++) // For rows
    {
        for(int j = 0; j < wallMap.getSize().x-1; j++) // For columns
        {
            blackPixels = 0;
            colors[0][0] = wallMap.getPixel(j,i);
            colors[1][0] = wallMap.getPixel(j+1,i);
            colors[0][1] = wallMap.getPixel(j,i+1);
            colors[1][1] = wallMap.getPixel(j+1,i+1);
            for(int k = 0; k<2; k++)
            {
                for(int l = 0; l<2; l++)
                {
                    if(colors[k][l] == sf::Color::Black)
                        blackPixels++;
                }
            }
            if(blackPixels == 1)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::Black)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((j+k)*4,(i+l)*4);
                                std::cout<<"punto: "<<(j+k)*4<<","<<(i+l)*4<<" iniciado\n";
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+k)*4,(i+l)*4);
                                std::cout<<"punto: "<<(j+k)*4<<","<<(i+l)*4<<" finalizado\n";
                                ceilings.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
            if(blackPixels == 3)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::White)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((j+abs(k-1))*4,(i+abs(l-1))*4);
                                std::cout<<"punto: "<<(j+abs(k-1))*4<<","<<(i+abs(l-1))*4<<" iniciado\n";
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+abs(k-1))*4,(i+abs(l-1))*4);
                                std::cout<<"punto: "<<(j+abs(k-1))*4<<","<<(i+abs(l-1))*4<<" finalizado\n";
                                ceilings.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
        }
    }
    // For walls
    for(int i = 0; i < wallMap.getSize().y-1; i++) // For rows
    {
        for(int j = 0; j < wallMap.getSize().x-1; j++) // For columns
        {
            blackPixels = 0;
            colors[0][0] = wallMap.getPixel(i,j);
            colors[1][0] = wallMap.getPixel(i+1,j);
            colors[0][1] = wallMap.getPixel(i,j+1);
            colors[1][1] = wallMap.getPixel(i+1,j+1);
            for(int k = 0; k<2; k++)
            {
                for(int l = 0; l<2; l++)
                {
                    if(colors[k][l] == sf::Color::Black)
                        blackPixels++;
                }
            }
            if(blackPixels == 1)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::Black)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((i+k)*4,(j+l)*4);
                                std::cout<<"punto: "<<(i+k)*4<<","<<(j+l)*4<<" iniciado\n";
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+k)*4,(j+l)*4);
                                std::cout<<"punto: "<<(i+k)*4<<","<<(j+l)*4<<" finalizado\n";
                                walls.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
            if(blackPixels == 3)
            {
                for(int k = 0; k<2; k++)
                {
                    for(int l = 0; l<2; l++)
                    {
                        if(colors[k][l] == sf::Color::White)
                        {
                            if(!end)
                            {
                                auxLine.pointA = sf::Vector2i((i+abs(k-1))*4,(j+abs(l-1))*4);
                                std::cout<<"punto: "<<(i+abs(k-1))*4<<","<<(j+abs(l-1))*4<<" iniciado\n";
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+abs(k-1))*4,(j+abs(l-1))*4);
                                std::cout<<"punto: "<<(i+abs(k-1))*4<<","<<(j+abs(l-1))*4<<" finalizado\n";
                                walls.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
        }
    }
}
void Map::checkCollision()
{
    for(int i = 0; i<walls.size(); i++)
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
    for(int i = 0; i<ceilings.size(); i++)
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