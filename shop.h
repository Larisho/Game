#ifndef SHOP_H
#define SHOP_H

#include "player.h"

class Shop {
private:
    // add private members
    void printMenu(int);
    bool canBuy(int, int);
    void makeTransaction(Player*, int);
public:
    // add public members
    Shop();
    void goToShop(Player*);

};

#endif // SHOP_H
