

#ifndef DICE_H
#define DICE_H

#include "die.h"
#include <vector>

using namespace std;

class Dice
{
private:
    vector<die> dice;
    int numOfDie,
    sides;
    
    void init();
    
public:
    Dice();
    Dice(int numberOfDice);
    Dice(int numberOfDice, int numberOfSides);
    void roll();
    void reroll(int die);
    vector<int> getValues();
    int getValue(int die);
    int sum();
    int operator[](int die);
};

#endif
