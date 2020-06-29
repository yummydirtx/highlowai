#include <iostream>
#include <string>

int introduceUser() {
    std::string wantPlay;
    std::cout << "Hello and welcome to High/Low ai!" << std::endl
    << "Hopefully this program should guess any number 1-100 in less than 10 turns!" << '\n'
    << "Would you like to play? (Y,n) ";
    std::cin >> wantPlay;
    if (wantPlay == "n") {
        std::cout << "Ok, goodbye!" << '\n';
        return 1;
    }
    std::cout << "Let's play! Think of a number between 1 and 100" << '\n';
    return 0;
}

void finalStats(int numberOfTimes) {
    std::cout << "Thanks for playing!\n"
    << "Your number took the AI " << numberOfTimes << " turns to find.\n";
}