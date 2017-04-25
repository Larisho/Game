#ifndef PLAYER_H
#define PLAYER_H

#include "livingCreature.h"
#include <string>

class Player : public LivingCreature {
private:
    int cardio;
    int experience;
    int maxExperience;
    int level;
    int gold;
public:
    Player(std::string nm) : LivingCreature(nm, 1, 1, 8) /* name, attack, defense, health */ {
        this->experience = 0;
        this->maxExperience = 2;
        this->cardio = 1;
        this->level = 1;
        this->gold = 0;
    }

    int getExperience();
    int getMaxExperience();
    int getCardio();
    int getLevel();
    int getGold();

    void setExperience(int);
    void setMaxExperience(int);
    void setCardio(int);
    void setLevel(int);
    void setGold(int);

    void raiseAttack(int);
    void raiseCardio(int);
    void raiseDefense(int);
    void raiseHealth(int);

    void addGold(int);
    void addExperience(int);
    bool hasEnoughExperience();
    void levelUp();
    void increaseStat();
    void printStats();

    int attack();
    void isAttacked(int);
};
#endif // PLAYER_H
