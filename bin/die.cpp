#include "die.h"
#include <stdlib.h> //For rand()

die::die() { 
    val = 0; 
    sides = 6;
}

die::die(int s) {
    val = 0;
    sides = s;
}

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