#include <stdlib.h> //For rand()
#include <time.h>
#include "Die.h"
#include <stdexcept>

Die::Die() {
    sides = 6;
    value = 0;
    srand (time(NULL));
}


Die::Die(int numberOfSides) {
    if (numberOfSides < 2) {
        throw std::invalid_argument("Die must have at least two sides");
    }
    
    sides = numberOfSides;
    value = 0;
    srand (time(NULL));
}


void Die::roll() {
    value = rand() % sides + 1;
}

int Die::getValue() {
    return value;
}


int Die::operator+(Die& die) {
    return value + die.value;
}


int Die::operator+(int val) {
    return value + val;
}


bool Die::operator==(Die& die) {
    return value == die.value;
}


bool Die::operator==(int val) {
    return value == val;
}
