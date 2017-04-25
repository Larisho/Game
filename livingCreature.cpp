#include "livingCreature.h"

LivingCreature::LivingCreature(std::string name, int att, int def, int hp) {
    this->name = name;
    this->att = att;
    this->def = def;
    this->hp = hp;
    this->maxHp = hp;
    this->alive = true;
}

std::string LivingCreature::getName() {
    return this->name;
}

int LivingCreature::getAttack() {
    return this->att;
}

int LivingCreature::getDefense() {
    return this->def;
}

int LivingCreature::getHealth() {
    return this->hp;
}

int LivingCreature::getMaxHealth() {
    return this->maxHp;
}

void LivingCreature::setName(std::string nm) {
    this->name = nm;
}

void LivingCreature::setAttack(int att) {
    this->att = att;
}

void LivingCreature::setDefense(int def) {
    this->def = def;
}

void LivingCreature::setHealth(int hp) {
    this->hp = hp;
}

void LivingCreature::setMaxHealth(int hp) {
    this->maxHp = hp;
}

bool LivingCreature::isAlive() {
    return this->alive;
}

void LivingCreature::kill() {
    this->alive = false;
}

void LivingCreature::reanimate() {
    this->alive = true;
}

void LivingCreature::isAttacked(int dmg) {
    this->hp -= dmg;
}

int LivingCreature::attack() {
    return this->att;
}
