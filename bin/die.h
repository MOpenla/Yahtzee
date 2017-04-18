#ifndef DIE_H
#define DIE_H


class Die {
private:
    int value,
    sides;
    
public:
    Die();
    Die(int numberOfSides);
    void roll();
    int getValue();
    int operator+(Die& die);
    int operator+(int val);
    bool operator==(Die& die);
    bool operator==(int val);
};

#endif
