
#include "Dice.h"
#include <stdexcept>

Dice::Dice() {
    numOfDie = 5;
    sides = 6;
}

Dice::Dice(int numberOfDice) {
    if (numberOfDice < 1) {
        throw invalid_argument("Number of dice cannot be less than one!");
    }
    
    numOfDie = numberOfDice;
    sides = 6;
}

void Dice::roll() {
    for (int i = 0; i < numOfDie; i++) {
        dice[i].roll();
    }
}

void Dice::reroll(int die) {
    if (die < 1) {
        throw out_of_range( "Die must be positive!");
    } else if (die > numOfDie) {
        throw out_of_range("Not that many die available!");
    }
    
    dice[die-1].roll();
}

vector<int> Dice::getValues() {
    vector<int> temp;
    
    for (int i = 0; i < numOfDie; i++) {
        temp.push_back(dice[i].getValue());
    }
    
    return temp;
}

int Dice::getValue(int die) {
    if (die < 1) {
        throw out_of_range( "Die must be positive!");
    } else if (die > numOfDie) {
        throw out_of_range("Not that many die available!");
    }
    
    return dice[die-1].getValue();
}

int Dice::sum() {
    int sum = 0;
    
    for (int i = 0; i < numOfDie; i++) {
        sum = dice[i] + sum;
    }
    
    return sum;
}
int Dice::operator[](int die) {
    if (die < 1) {
        throw out_of_range( "Die must be positive!");
    } else if (die > numOfDie) {
        throw out_of_range("Not that many die available!");
    }
    
    return dice[die-1].getValue();
}

