#ifndef UTIL_H
#define UTIL_H

#include <string>

void printTitleScreen();
void printActionMenu(std::string);
void clearScreen();

std::string getPlayerName();

char getUserInput();

int getRandomNumberBetween(int, int);

#endif // UTIL_H
