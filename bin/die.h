#ifndef _DIE_H_
#define _DIE_H_

class die {
public:
    int getValue() { return rand() % 6 + 1; }
};

#endif