#include <Entity.h>

class Map: public Entity
{
private:
    /* data */
public:
    Map(/* args */);
    ~Map();
    Map(float,float,float,std::string);
    ~Map();
    sf::Sprite get();
    void initTexture();
    void initSprite();
};

Map::Map(/* args */)
{
}

Map::~Map()
{
}
