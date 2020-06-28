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

int playGame() {
    std::string inputLetter;
    int outputNumber;
    int upperRange{100};
    int lowerRange{0};
    std::cout << findMiddle(upperRange, lowerRange);
    return 0;
}