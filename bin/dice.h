#ifndef _DICE_H_
#define _DICE_H_

#include "die.h" //TODO: this doesn't need to be in here

class dice {

private:
    std::vector<die> dies;

public:
    dice() { 
        for(int i = 0; i < 6; i++) {
            die d;
            dies.push_back(d);
        }
    };

    std::vector<int> getValues() { 
        std::vector<int> temp;

        for(int i = 0; i < dies.size(); i++) {
            temp.push_back( dies[i].getValue() );
        }

        return temp; 
    }
    void roll() { 
        for(int i = 0; i < dies.size(); i++) {
            dies[i].roll();
        }
    };
};

#endif