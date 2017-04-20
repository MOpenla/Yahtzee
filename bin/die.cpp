#include "die.h"
#include <stdlib.h> //For rand()
#include <stdexcept> //For invalid_argument

/******************************************************************************
 *                                Constructors                                *
 ******************************************************************************/
die::die() { 
    val = 0; 
    sides = 6;
}

die::die(int s) {
    val = 0;

    if (s < 2) {
        throw std::invalid_argument("Die must have at least two sides");
    }

    sides = s;
}

/******************************************************************************
 *                               Public Methods                               *
 ******************************************************************************/
void die::roll() { 
    val = rand() % sides + 1; 
}

int die::getValue() { 
    return val; 
}

int die::operator+(die right) { 
    return val + right.val; 
}

int die::operator+(int right) { 
    return val + right; 
}

bool die::operator==(die right) { 
    return val == right.val; 
}

bool die::operator==(int right) { 
    return val == right; 
}

