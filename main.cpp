#include <iostream>
#include <iomanip>
#include "livingCreature.h"
#include "player.h"
#include "monster.h"
#include "monsterFactory.h"
#include "shop.h"
#include "util.h"

/**
 * @Author: Gabriele Bianchet-David
 * @Title: TBD
 * @Version: 1.0.0
 *
 * This game is supposed to be run through the command line
 * in windows. It's a little text based adventure game that
 * can entertain for hours. Hopefully this works.
*/

using namespace std;

/*void fight(int &megahealth, int &charhealth, int chardamage, bool &dead, bool &mdead, int mlvl) {
    char choice;
    dead = false;
    mdead = false;
    cout << "Press any character to attack!" << endl;
    cin >> choice;
    cout << endl;
    if (choice)
    {
        // Hurt the creature
        cout << "You did " << chardamage << " point(s) of damage!" << endl;
        cout << "The creature has " << megahealth << " health point(s) left!" << endl;
        if (megahealth <= 0)
        {
            cout << "Congrats! You have defeated the creature!" << endl;
            mdead = true;
            return;
        }
    }
    cout << endl;
    cout << "It attacked you!" << endl;
    int megadamage = 3; // TODO: calculate how much damage monster does
    int def = 0; // TODO: calculate damage done on char
    charhealth = charhealth - def;
    cout << "It did " << megadamage << " point(s) of damage!" << endl;
    cout << "Your defense has blocked " << def << " point(s) of damage!" << endl;
    cout << endl;
    if (charhealth <= 0)
    {
        cout << "Oh no! Looks like the monster has bested you!\nGame Over!" << endl;
        dead = true;
        return;
    }
} */
/*bool fightSequ(int mlvl, int& health, int mhp, int dmg, string name)
{
    bool dead, mdead;

    //if(r < 15)
    //{
        //cout << "Oh no! you've been attacked by " << mobCount() << " Monsters!" << endl;

    //}
    //else
    //{
        cout << "An Ematar level " << mlvl << " attacked you!" << endl;
        cout << name <<": " << health << " hp" << "          " << "Ematar: " << mhp << " hp" << endl;
        while (mdead == false)
        {
            fight(mhp, health, dmg, dead, mdead, mlvl);
            cout << name <<": " << health << " hp" << "          " << "Ematar: " << mhp << " hp" << endl;
            if (dead == true)
                return true;
        }
        cout << endl;
        cout << "You have gained " << 2 << " EXP!" << endl;
        int goldg = goldGain(mlvl);
        cout << "You gained " << goldg << " Gold!" << endl;
        int gold = goldg;
        cout << endl;
        /*while (experience >= max_exp)
        {
            experience = experience - max_exp;
            level = level + 1;
            max_exp = max_exp + (level * 2);
            cout << "Level up!\nYou have reached level " << level << "!" << endl;
            cout << "Your health has been restored!" << endl << endl;
            health = charHealth();
            stat_increase(name);
        }
    //}
    mdead = false;
    dead = false;
    return false;
} */

void worldMap()
{
    cout << "The map hasn't been created yet..." << endl;
}

/**
 * Add moves and different monsters. Possibly
 * different monsters for different map areas.
 * Make map
 * ***I guess you did some stuff...***
 * Probably should work on a campain/storyline
 *
 * Okay so here's the deal:
 * use classes to make moves
 * add some sort of agility factor (random number based) to decide who attacks first
 * add like intrinsic abilities
 * maybe multiple different types of monsters in a mob
 * finish map stuff
 */
int main() {
    printTitleScreen();
    char choice;
    Player p(getPlayerName());
    MonsterFactory mFact(&p);
    Shop shop;
    while (true) {
        printActionMenu(p.getName());

        choice = getUserInput();

        switch (choice) {
          case 'b': {
              Monster m = mFact.makeMonster();

              cout << "Monster " << m.getName() << " is trying to attack " << p.getName() << "!" << endl;
              cout << "He has these stats: " << endl;
              cout << "level: " << m.getLevel() << endl;
              cout << "health: " << m.getHealth() << endl;
              cout << "att: " << m.getAttack() << endl;
              cout << "def: " << m.getDefense() << endl;
              break;
          }
          case 's': {
              p.printStats();
              break;
          }
          case 't': {
              shop.goToShop(&p);
              break;
          }
          case 'm': {
              worldMap();
              break;
          }
          case 'q': {
              clearScreen();
              return 0;
          }
          default:
            cout << "Incorrect input. Please try again." << endl;
        }

    }
}
