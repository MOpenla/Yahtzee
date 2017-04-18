

#ifndef DICE_H
#define DICE_H

#include "Die.h"
#include <vector>

using namespace std;

class Dice
{
private:
    vector<Die> dice;
    int numOfDie,
    sides;
    
public:
    Dice();
    Dice(int numberOfDice);
    void roll();
    void reroll(int die);
    vector<int> getValues();
    int getValue(int die);
    int sum();
    int operator[](int die);
};

#endif
