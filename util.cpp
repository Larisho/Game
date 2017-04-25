#include "util.h"
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <locale>

void printTitleScreen() {
    std::string firstLine, secondLine, thirdLine, fourthLine;

    firstLine  = "--.--,---.    --.--|   |,---.    ,--. ,---.,---.--.--|   |";
    secondLine = "  |  |   |      |  |---||---     |   ||--- |---|  |  |---|";
    thirdLine  = "  |  |   |      |  |   ||        |   ||    |   |  |  |   |";
    fourthLine = "  `  `---'      `  `   '`---'    `--' `---'`   '  `  `   '";

    clearScreen();

    printf("\n\n");
    printf("%10s%s\n", " ", firstLine.c_str());
    printf("%10s%s\n", " ", secondLine.c_str());
    printf("%10s%s\n", " ", thirdLine.c_str());
    printf("%10s%s\n", " ", fourthLine.c_str());
    printf("%45s", "Press enter...");

    std::cin.ignore();
    clearScreen();
}

void printActionMenu(std::string name) {
    std::cout << "So " << name << "," << std::endl;
    std::cout << "What would you like to do?" << std::endl;
    std::cout << "  [B]attle?" << std::endl;
    std::cout << "  [S]tats?" << std::endl;
    std::cout << " S[T]ore?" << std::endl;
    std::cout << "  [M]ap?" << std::endl;
    std::cout << "  [Q]uit?" << std::endl;
}

void clearScreen() {
#ifdef _WIN32
    if (std::getenv("HOME"))
        std::system("clear");
    else
        std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

std::string getPlayerName() {
	std::string name;
    std::cout << "What is your name, Adventurer?" << std::endl;
    getline(std::cin, name);
    if (name.length() > 40)
        name = name.substr(0, 40);

    return name;
}

char getUserInput() {
    std::locale loc;
	std::string input;
	getline(std::cin, input);

	return tolower(input[0], loc);
}

int getRandomNumberBetween(int min, int max) {
    srand (time(NULL));
    return rand()%(max-min + 1) + min;
}
