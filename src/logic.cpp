#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

int findMiddle(int upper, int lower) {
    float halfNumber{(float(upper) + float(lower)) / 2};
    srand(time(0));
    int upOrDown{rand() % 50};
    if (upOrDown >= 25) {
        return int(std::ceil(halfNumber));
    } else {
        return int(std::floor(halfNumber));
    }
}

std::string askNumber(int asked) {
    std::string letter;
    std::cout << "Is your number " << asked << '\n';
    std::cout << "(H)igher, (L)ower, (C)orrect, (Q)uit (answer in a capital letter): ";
    std::cin >> letter;
    return letter;
}

int playGame() {
    std::string inputLetter;
    bool numberFound{false};
    int middleNumber;
    int outputNumber{0};
    int upperRange{100};
    int lowerRange{0};
    while (numberFound == false) {
        outputNumber++;
        middleNumber = findMiddle(upperRange, lowerRange);
        inputLetter = askNumber(middleNumber);
        if (inputLetter == "H") {
            lowerRange = middleNumber;
        } else if (inputLetter == "L") {
            upperRange = middleNumber;
        } else if (inputLetter == "C") {
            numberFound = true;
            std::cout << "The number is " << middleNumber;
        } else if (inputLetter == "Q") {
            return 100;
        } else {
            return 150;
        }
    }
    return outputNumber;
}