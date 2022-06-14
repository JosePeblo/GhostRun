#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <player.h>
#include <Enemy.h>
class Battle
{
    public:
        Battle(std::string,Player&,Enemy&);
        Player* player;
        Enemy* enemy;
        bool playerTurn = true;
    private:
};



#endif