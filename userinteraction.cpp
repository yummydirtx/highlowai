#include <iostream>
#include <string>

void introduceUser() {
    std::string wantPlay;
    std::cout << "Hello and welcome to High/Low ai!" << std::endl
    << "If there are any bugs we would appreciate a bug report." << '\n'
    << "Would you like to play? (Y,n) ";
    std::cin >> wantPlay;
    std::cout << wantPlay;
}