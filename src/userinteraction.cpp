#include <iostream>
#include <string>

int introduceUser() {
    std::string wantPlay;
    std::cout << "Hello and welcome to High/Low ai!" << std::endl
    << "Hopefully this program should guess any number 1 to any number!" << '\n'
    << "Would you like to play? (Y,n) ";
    std::cin >> wantPlay;   //check if the user wants to play
    if (wantPlay == "n") {
        std::cout << "Ok, goodbye!" << '\n';
        return 1;   //tells the main function to exit
    }
    std::cout << "Let's play! Think of a number between 1 and your upper range." << '\n';
    return 0;   //tells the main function to continue
}

void finalStats(int numberOfTimes) {
    std::cout << "Thanks for playing!\n"
    << "Your number took the AI " << numberOfTimes << " turns to find.\n";
}