#include <iostream>     //Used for input and output
#include "hlheader.h"   //Integrate other source files

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
    if (logicExit == 100) {
        std::cout << "Come back soon!";
        return 0;
    } else if (logicExit == 150) {
        std::cout << "Error (code 1): Incorrect Input";
        return 1;
    }
    //Output number of guesses needed to find
    
    return 0;
}