#include "dice.h"
#include <stdexcept> //For invalid_argument
#include <string>

dice::dice() { 
    for (int i = 0; i < 6; i++) {
        die d;
        dies.push_back(d);
    }
}

void dice::roll() { 
    for (int i = 0; i < dies.size(); i++) {
        dies[i].roll();
    }
}

void dice::roll(int die) {
    if ( die < 1 || die > dies.size() ) {
        std::string message = "Die must be between 1 and numOfDice (inclusive)";
        throw std::invalid_argument(message);
    }

    dies[die-1].roll();
}

std::vector<int> dice::getValues() { 
    std::vector<int> temp;

    for (int i = 0; i < dies.size(); i++) {
        temp.push_back( dies[i].getValue() );
    }

    return temp; 
}

int dice::getValue(int die) {
    if ( die < 1 || die > dies.size() ) {
        std::string message = "Die must be between 1 and numOfDice (inclusive)";
        throw std::invalid_argument(message);
    }

    return dies[die-1].getValue();
}

int dice::operator[](int die) {
    return dies[die-1].getValue();
}

int dice::sum() {
    int sum = 0;

    for (int i = 0; i < dies.size(); i++) {
        sum = dies[i] + sum;
    }

    return sum;
}