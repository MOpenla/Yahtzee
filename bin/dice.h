#ifndef _DICE_H_
#define _DICE_H_

#include "die.h"
#include <vector>

class dice {

private:
    std::vector<die> dies;

public:
    dice();

    void roll();
    std::vector<int> getValues();
    int getValue(int die);
};

#endif