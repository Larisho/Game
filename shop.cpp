#include "shop.h"
#include "player.h"
#include "util.h"
#include <iostream>

Shop::Shop() {
    // create all the items and put them into the store
}

void Shop::printMenu(int gold) { // create this menu dynamically
    std::cout << "Welcome to the store!" << std::endl;
    std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl << std::endl;
    std::cout << "Here are the goods available!" << std::endl;
    std::cout << "[H]ealth! ............5 Gold" << std::endl;
    std::cout << "[M]uscle-Up!..........35 Gold" << std::endl;
    std::cout << "[S]hield!.............35 Gold" << std::endl;
    std::cout << "[O]xygen Tank!........35 Gold" << std::endl;
    std::cout << "[Q]uit Menu" << std::endl << std::endl << std::endl;
    std::cout << "You have:             " << gold << " Gold" << std::endl;
}

bool Shop::canBuy(int gold, int price) {
    return gold >= price ? true : false;
}

void Shop::makeTransaction(Player* p, int price) {
    p->addGold(-1 * price);
}

void Shop::goToShop(Player* p) {
    char choice = '-';

    while(choice != ' ') {
        this->printMenu(p->getGold());

        choice = getUserInput();

        switch(choice) {
            case 'h':
                if (!this->canBuy(p->getGold(), 5)) {
                    std::cout << "You do not have enough funds to purchase this item! Sorry" << std::endl << std::endl << std::endl;
                    break;
                }
                makeTransaction(p, 5);
                std::cout << "Your health has been replenished by 5 points!" << std::endl << std::endl << std::endl;
                p->raiseHealth(5);
                if (p->getHealth() > p->getMaxHealth())
                    p->setHealth(p->getMaxHealth());
                break;
            case 'm':
                if (!this->canBuy(p->getGold(), 35)) {
                    std::cout << "You do not have enough funds to purchase this item! Sorry" << std::endl << std::endl << std::endl;
                    break;
                }
                makeTransaction(p, 35);
                p->raiseAttack(1);
                std::cout << "Congrats! You've raised your Strength stat by 1!" << std::endl << std::endl << std::endl;
                break;
            case 's':
                if (!this->canBuy(p->getGold(), 35)) {
                    std::cout << "You do not have enough funds to purchase this item! Sorry" << std::endl << std::endl << std::endl;
                    break;
                }
                makeTransaction(p, 35);
                p->raiseDefense(1);
                std::cout << "Congrats! You've raised your Defense stat by 1!" << std::endl << std::endl << std::endl;
                break;
            case 'o':
                if (!this->canBuy(p->getGold(), 35)) {
                    std::cout << "You do not have enough funds to purchase this item! Sorry" << std::endl << std::endl << std::endl;
                    break;
                }
                makeTransaction(p, 35);
                p->raiseCardio(1);
                std::cout << "Congrats! You've raised your Stamina stat by 1!" << std::endl << std::endl << std::endl;
                break;
            case 'q':
                std::cout << std::endl << std::endl << std::endl;
                choice = ' ';
                return;
            default:
                std::cout << "That's an incorrect input :( come on dude\nTry again" << std::endl << std::endl << std::endl;
                break;
        }
    }
}
