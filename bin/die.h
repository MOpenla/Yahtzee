#ifndef _DIE_H_
#define _DIE_H_

class die {
private:
    int val;
public:
    die() { val = 0; }

    void roll() { val = rand() % 6 + 1; }
    int getValue() { return val; }
};

#endif