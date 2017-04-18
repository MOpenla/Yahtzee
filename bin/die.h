#ifndef _DIE_H_
#define _DIE_H_

class die {
private:
    int val;
public:
    die();

    void roll();
    int getValue();
    int operator+(die right);
    int operator+(int right);
    bool operator==(die right);
    bool operator==(int right);
};

#endif