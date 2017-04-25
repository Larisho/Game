#include "monsterFactory.h"
#include "player.h"
#include "monster.h"
#include "util.h"

MonsterFactory::MonsterFactory(Player* player) {
    this->player = player;
}

std::string MonsterFactory::names[NUM_OF_MONSTERS] = {"Quizzy", "Moop", "Tarball", "FooBar", "Baz"};

int MonsterFactory::levels[NUM_OF_MONSTERS] = {4, 8, 15, 35, 50};

int MonsterFactory::attacks[NUM_OF_MONSTERS] = {1, 4, 10, 29, 46};

int MonsterFactory::defenses[NUM_OF_MONSTERS] = {0, 2, 5, 20, 30};

Monster MonsterFactory::makeMonster() {
    std::string name;
    int level, attack, defense, health;
    name = generateName();

    int indexOfName;

    for(int i = 0; i < NUM_OF_MONSTERS; i++) {
        if (name == names[i]) {
            indexOfName = i;
            break;
        }
    }

    level = generateLevel(indexOfName);
    health = generateHealth(indexOfName, level);
    attack = generateAttack(indexOfName, level);
    defense = generateDefense(indexOfName, level);

    return Monster(name, level, attack, defense, health);
}

Player* MonsterFactory::getPlayer() {
    return this->player;
}

void MonsterFactory::setPlayer(Player* player) {
    this->player = player;
}

int MonsterFactory::generateLevel(int name) {
    int raw =  this->levels[name] + (getRandomNumberBetween(0, 7) * (getRandomNumberBetween(0, 4) <= 1 ? -1 : 1));

    if (raw == 0) {
        return 1;
    }
    else if (raw < 0) {
        return raw *= -1;
    }
    else {
        return raw;
    }
}

int MonsterFactory::generateAttack(int name, int lvl) {
    int baseAtt = this->attacks[name];
    int baseLvl = this->levels[name];

    int att = baseAtt + (lvl - baseLvl) + (baseAtt * 0.25);

    return att <= 0 ? 1 : att;
}

int MonsterFactory::generateDefense(int name, int lvl) {
    int baseDef = this->defenses[name];
    int baseLvl = this->levels[name];

    int def = baseDef + (lvl - baseLvl);

    return def <= 0 ? 1 : def;
}

int MonsterFactory::generateHealth(int name, int lvl) {
    int baseHealth = this->levels[name];
    int multiplier = 1.5;

    return (baseHealth * multiplier) + lvl;
}

std::string MonsterFactory::generateName() {
    int lvl = this->player->getLevel();
    std::string name;
    int maxMonster;

    for(int i = 0; i < NUM_OF_MONSTERS; i++) {
        if (this->levels[i] > lvl) {
            maxMonster = i;
            break;
        }
    }

    return 0 == maxMonster ? this->names[0] : this->names[getRandomNumberBetween(0, maxMonster)];
}
