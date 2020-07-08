#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int findMiddle(int upper, int lower) {
    float halfNumber{(float(upper) + float(lower)) / 2};    //find the exact middle number
    srand(time(0));     //seed the random number generator
    int upOrDown{rand() % 50};
    if (upOrDown >= 25) {   //round the number up or down
        return int(std::ceil(halfNumber));
    } else {
        return int(std::floor(halfNumber));
    }
}

std::string askNumber(int asked, int older) {
    if (asked != older) {
    std::string letter;
    std::cout << "Is your number " << asked << "?\n";
    std::cout << "(H)igher, (L)ower, (C)orrect, (Q)uit (answer in a capital letter): ";
    std::cin >> letter;
    std::cout << "\n";
    return letter;
    } else {
        return "try";   //if the number has already been asked try again
    }
}

int playGame() {
    std::string inputLetter;
    bool numberFound{false};
    int oldNumber{0};
    int middleNumber;
    int outputNumber{0};
    int upperRange{100};
    int lowerRange{0};
    bool mistype{false};
    while (numberFound == false) {
        middleNumber = findMiddle(upperRange, lowerRange);
        inputLetter = askNumber(middleNumber, oldNumber);
        mistype = false;
        while (!mistype) {
            if (inputLetter == "H" || inputLetter == "h") {
                lowerRange = middleNumber;  //set the lower range if the number is higher
                outputNumber++;     //increment the turn counter
                mistype = true;
            } else if (inputLetter == "L" || inputLetter == "l") {
                upperRange = middleNumber;  //set the upper range if the number is lower
                outputNumber++;
                mistype = true;
            } else if (inputLetter == "C" || inputLetter == "c") {
                numberFound = true; //break out of the loop
                std::cout << "The number is " << middleNumber << '\n';
                mistype = true;
            } else if (inputLetter == "Q" || inputLetter == "q") {
                return 100;         //tell the main function the user exited
            } else if (inputLetter == "try") {
                if (outputNumber > 10) {
                    return 200;     //tell the main function the user has cheated
            }
            } else {
                std::cout << "Oops! Try again: ";         //tell the main function the user has mistyped
                std::cin >> inputLetter;
                std::cout << std::endl;
            }
        }
    }
    return outputNumber;    //tell the main function how many turns it took
}