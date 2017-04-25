#ifndef MONSTER_H
#define MONSTER_H

#include "livingCreature.h"
#include <string>

class Monster : public LivingCreature {
private:
    int level;

public:
    Monster(std::string name, int lvl, int att, int def, int hp) : LivingCreature(name, att, def, hp) {
        this->level = lvl;
    }

    int getLevel();
    void setLevel(int);

    int attack();
    void isAttacked(int);
};

#endif // MONSTER_H
