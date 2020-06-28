#include <iostream>
#include "hlheader.h"

//This should hopefully work as an AI high low player.
//Hopefully the player doesn't cheat

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
    //Output number of guesses needed to find
    return 0;
}