#ifndef _DIE_H_
#define _DIE_H_

class die {
private:
    int val;
public:
    die() { val = 0; }

    void roll() { val = rand() % 6 + 1; }
    int getValue() { return val; }
    int operator+(die right) { return val + right.val; }
    int operator+(int right) { return val + right; }
    bool operator==(die right) { return val == right.val; }
    bool operator==(int right) { return val == right; }
};

#endif