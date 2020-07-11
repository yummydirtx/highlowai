#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

static int findMiddle(int upper, int lower) {
    float halfNumber{(float(upper) + float(lower)) / 2};    //find the exact middle number
    srand(time(0));     //seed the random number generator
    int upOrDown{rand() % 50};
    if (upOrDown >= 25) {   //round the number up or down
        return int(std::ceil(halfNumber));
    } else {
        return int(std::floor(halfNumber));
    }
}

static std::string askNumber(int asked, int older) {
    if (asked != older) {
    std::string letter;
    std::cout << "Is your number " << asked << "?\n";
    std::cout << "(H)igher, (L)ower, (C)orrect, (Q)uit: ";
    std::cin >> letter;
    std::cout << "\n";
    return letter;
    } else {
        return "try";   //if the number has already been asked try again
    }
}

static long long int askUpper() {
    int upperNumber{100};
    std::cout << "What should the upper range of guessed numbers be?" << '\n' << "Enter a number (Default is 100): ";
    std::cin >> upperNumber;
    std::cout << std::endl;
    if (upperNumber > 223,372,036,854,775,806 || upperNumber < 1) {
        return 0;
    }
    return upperNumber;
}

int playGame() {
    std::string inputLetter;
    bool numberFound{false};
    bool inRange{false};
    int oldNumber{0};
    long long int middleNumber;
    long int outputNumber{0};
    long long int upperRange{100};
    long long int lowerRange{0};
    bool mistype{false};
    while (!inRange) {
        upperRange = askUpper();
        if (upperRange != 0) {
            inRange = true;
        } else {
            std::cout << "Out of range! Try again." << '\n';
        }
    }
    while (numberFound == false) {
        middleNumber = findMiddle(upperRange, lowerRange);
        inputLetter = askNumber(middleNumber, oldNumber);
        mistype = false;
        while (!mistype) {
            if (inputLetter == "H" || inputLetter == "h") {
                lowerRange = middleNumber;  //set the lower range if the number is higher
                oldNumber = middleNumber;
                outputNumber++;     //increment the turn counter
                mistype = true;
            } else if (inputLetter == "L" || inputLetter == "l") {
                upperRange = middleNumber;  //set the upper range if the number is lower
                oldNumber = middleNumber;
                outputNumber++;
                mistype = true;
            } else if (inputLetter == "C" || inputLetter == "c") {
                numberFound = true; //break out of the loop
                std::cout << "The number is " << middleNumber << '\n';
                mistype = true;
            } else if (inputLetter == "Q" || inputLetter == "q") {
                return 100;         //tell the main function the user exited
            } else if (inputLetter == "try") {
                if (upperRange == lowerRange) {
                    return 200;     //tell the main function the user has cheated
                }
                mistype = true;
            } else {
                std::cout << "Oops! Try again: ";         //tell the main function the user has mistyped
                std::cin >> inputLetter;
                std::cout << std::endl;
            }
        }
    }
    return outputNumber;    //tell the main function how many turns it took
}