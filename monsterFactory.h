#ifndef MONSTERFACTORY_H
#define MONSTERFACTORY_H

#include "monster.h"
#include "player.h"
#define NUM_OF_MONSTERS 5

class MonsterFactory {
private:
    // Put private stuff here
    Player* player;
    static std::string names[];
    static int levels[];
    static int attacks[];
    static int defenses[];

    int generateLevel(int);
    int generateAttack(int, int);
    int generateDefense(int, int);
    int generateHealth(int, int);

    std::string generateName();
public:
    // Put public stuff here
    MonsterFactory(Player*);
    Monster makeMonster();

    Player* getPlayer();
    void setPlayer(Player*);
};

#endif // MONSTERFACTORY_H
