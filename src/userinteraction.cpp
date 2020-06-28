#include <iostream>
#include <string>

int introduceUser() {
    std::string wantPlay;
    std::cout << "Hello and welcome to High/Low ai!" << std::endl
    << "If there are any bugs we would appreciate a bug report." << '\n'
    << "Would you like to play? (Y,n) ";
    std::cin >> wantPlay;
    if (wantPlay == "n") {
        std::cout << "Ok, goodbye!";
        return 1;
    }
    std::cout << "Let's play!" << '\n';
    return 0;
}