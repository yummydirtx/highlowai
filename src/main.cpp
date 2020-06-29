#include <iostream>     //Used for input and output
#include "hlheader.h"   //Integrate other source files

//This should hopefully work as an AI high low player.
//Written by Alex Frutkin in 2020

int main() {
    int introExit;
    int logicExit;
    //Do introductions
    introExit = introduceUser();
    if (introExit == 1) {
        return 1;
    }
    //Guess number and check with user
    logicExit = playGame();
    if (logicExit == 100) {
        std::cout << "Come back soon!" << '\n';
        return 0;
    } else if (logicExit == 150) {
        std::cout << "Error (code 1): Incorrect Input" << '\n';
        return 1;
    } else if (logicExit == 200) {
        std::cout << "Error (code 2): User error leading to program failure. Please try again" << '\n';
        return 1;
    }
    //Output number of guesses needed to find
    finalStats(logicExit);
    return 0;
}