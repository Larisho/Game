#include "livingCreature.h"
#include "monster.h"
#include "util.h"
#include <stdlib.h>
#include <time.h>

int Monster::getLevel() {
    return level;
}

void Monster::setLevel(int val) {
    level = val;
}

void Monster::isAttacked(int dmg) {
    int def = dmg - this->getDefense();
    if (def < 0)
        def = 0;
    this->setHealth(this->getHealth() - def);
    if (this->getHealth() <= 0)
        this->kill();
}

int Monster::attack() {
    int rawDmg;
    int r = getRandomNumberBetween(0, 100);

    if (r <= 45)
        rawDmg = this->level / 4;
    else if (r > 45 && r <= 70)
        rawDmg = this->level / 3;
    else if (r > 70 && r <= 90)
        rawDmg = this->level / 2;
    else
        rawDmg = this->level;

    return rawDmg + this->level;
}
