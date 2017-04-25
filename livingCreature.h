#ifndef LIVINGCREATURE_H
#define LIVINGCREATURE_H

#include <string>

class LivingCreature {
private:
    std::string name;
    int att;
    int def;
    int hp;
    int maxHp;
    bool alive;
public:
    LivingCreature(std::string, int, int, int);

    std::string getName();
    int getAttack();
    int getDefense();
    int getHealth();
    int getMaxHealth();

    void setName(std::string);
    void setAttack(int);
    void setDefense(int);
    void setHealth(int);
    void setMaxHealth(int);
    bool isAlive();
    void kill();
    void reanimate();

    virtual void isAttacked(int);
    virtual int attack();

};
#endif // LIVINGCREATURE_H

