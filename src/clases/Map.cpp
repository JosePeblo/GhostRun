#include <Map.h>

Map::Map()
{
}

Map::Map(std::string mapPath,std::string wallPath)
{
    this->wallMap.loadFromFile(wallPath);
    this->background.setPosition(sf::Vector2f(0.f,0.f));
    this->background.setScale(sf::Vector2f(4.f,4.f));
    this->texture.loadFromFile(mapPath);
    this->background.setTexture(this->texture);
    this->initLines();
}

void Map::update(Player& player)
{
    this->background.setPosition(-(player.getPos()-player.getFov()));
}

void Map::render(sf::RenderTarget& target)
{
    target.draw(this->background);
}

void Map::initLines()
{
    sf::Color colors[2][2];
    int blackPixels = 0;
    bool end = false;
    Line auxLine;
    // For roofs
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
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+k)*4,(i+l)*4);
                                roofs.push_back(auxLine);
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
                                auxLine.pointA = sf::Vector2i((j+abs(k-1))*4,
                                                              (i+abs(l-1))*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((j+abs(k-1))*4,
                                                              (i+abs(l-1))*4);
                                roofs.push_back(auxLine);
                                end = false;
                            }

                        }
                    }
                }
            }
        }
    }
    // For walls
    for(int i = 0; i < wallMap.getSize().x-1; i++) // For rows
    {
        for(int j = 0; j < wallMap.getSize().y-1; j++) // For columns
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
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+k)*4,(j+l)*4);
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
                                auxLine.pointA = sf::Vector2i((i+abs(k-1))*4,
                                                              (j+abs(l-1))*4);
                                end = true;
                            }
                            else
                            {
                                auxLine.pointB = sf::Vector2i((i+abs(k-1))*4,
                                                              (j+abs(l-1))*4);
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

const std::vector<Line> Map::getWalls() const
{
    return walls;
}
const std::vector<Line> Map::getRoofs() const
{
    return roofs;
}
