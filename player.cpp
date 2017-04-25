#include "player.h"
#include "livingCreature.h"
#include "util.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

int Player::getExperience() {
    return this->experience;
}

int Player::getMaxExperience() {
    return this->maxExperience;
}

int Player::getCardio() {
    return this->cardio;
}

int Player::getLevel() {
    return this->level;
}

int Player::getGold() {
    return this->gold;
}

void Player::setExperience(int exp) {
    this->experience = exp;
}

void Player::setMaxExperience(int exp) {
    this->maxExperience = exp;
}

void Player::setCardio(int car) {
    this->cardio = car;
}

void Player::setLevel(int lvl) {
    this->level = lvl;
}

void Player::setGold(int gld) {
    this->gold = gld;
}

void Player::raiseAttack(int dy) {
    this->setAttack(this->getAttack() + dy);
}

void Player::raiseCardio(int dy) {
    this->cardio += dy;
    this->setMaxHealth(this->getMaxHealth() + dy);
    this->setHealth(this->getMaxHealth());
}

void Player::raiseDefense(int dy) {
    this->setDefense(this->getDefense() + dy);
}

void Player::raiseHealth(int dy) {
    this->setHealth(this->getHealth() + dy);
}

void Player::addGold(int dy) {
    this->gold += dy;
}

void Player::addExperience(int dy) {
    this->experience += dy;
}

bool Player::hasEnoughExperience() {
    return this->experience >= this->maxExperience ? true : false;
}

void Player::levelUp() {
    while (this->hasEnoughExperience()) {
        this->experience = this->experience - this->maxExperience;
        this->level += 1;
        this->maxExperience += (this->level * 2);
        std::cout << "Level up!\nYou have reached level " << this->level << "!" << std::endl;
        std::cout << "Your health has been restored!" << std::endl << std::endl;
        this->setHealth(this->getMaxHealth());
        this->increaseStat();
    }
}

void Player::increaseStat() {
    char choice;
    bool badInput = true;

    std::cout << std::setw(5) << "Please pick a Stat to increase!" << std::endl;
    std::cout << std::setw(5) << "[C]ardio!    " << this->cardio << "+1?" << std::endl;
    std::cout << std::setw(5) << "[S]trength!  " << this->getAttack() << "+1?" << std::endl;
    std::cout << std::setw(5) << "[D]efense!   " << this->getDefense() << "+1?" << std::endl;
    std::cout << std::setw(5) << "If you don't know what to pick, press [H]!" << std::endl;

    while (badInput)
    {
        choice = getUserInput();
        switch(choice) {
        case 'c':
            this->cardio++;
            std::cout << "Congrats! Your Cardio is now level " << this->cardio;
            badInput = false;
            break;
        case 's':
            this->raiseAttack(1);
            std::cout << "Congrats! Your Strength is now level " << this->getAttack();
            badInput = false;
            break;
        case 'd':
            this->raiseDefense(1);
            std::cout << "Congrats! Your Defense is now level " << this->getDefense();
            badInput = false;
            break;
        case 'h':
            std::cout << "Here's the help menu!\nThe Cardio stat increases your maximum health\nThe Strength stat increases your maximum damage output\nThe Defense stat increases the amount of damage you block per attack\nHope that helped!" << std::endl;
            std::cout << "So, make your choice!";
            std::cout << std::endl;
            break;
        default:
            std::cout << "Input unrecognized, please try again." << std::endl;
            break;
        }

    }
}

void Player::printStats() {
    std::cout << this->getName() << std::endl;
    std::cout << "EXP: " << this->experience << "/" << this->maxExperience << std::endl;
    std::cout << "Level " << this->level << std::endl;
    std::cout << "Health: " << this->getHealth() << "/" << this->getMaxHealth() << std::endl;
    std::cout << "Strength: " << this->getAttack() << std::endl;
    std::cout << "Stamina: " << this->cardio << std::endl;
    std::cout << "Defense: " << this->getDefense() << std::endl;
    std::cout << this->gold << " Gold" << std::endl << std::endl;
    std::cout << std::string(3, '\n');
}

int Player::attack() {
    int r = getRandomNumberBetween(0, 100);
    int dmg = this->getAttack() + (this->level / 2);

    if (r < 10)
        return dmg * 3;
    else if (r < 33)
        return dmg * 2;
    else
        return dmg;
}

void Player::isAttacked(int dmg) {
    int def = dmg - this->getDefense();
    this->raiseHealth(-1 * (def < 0 ? 0 : def));
}
