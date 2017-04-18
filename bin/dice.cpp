//#include "die.h"
#include "dice.h"
//#include <vector>

dice::dice() { 
    for(int i = 0; i < 6; i++) {
        die d;
        dies.push_back(d);
    }
}

std::vector<int> dice::getValues() { 
    std::vector<int> temp;

    for(int i = 0; i < dies.size(); i++) {
        temp.push_back( dies[i].getValue() );
    }

    return temp; 
}
void dice::roll() { 
    for(int i = 0; i < dies.size(); i++) {
        dies[i].roll();
    }
}