#ifndef GAME_H
#define GAME_H

//#include "Dice.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class game{
    private:
        void Display(int []);
        
    public:
        game();
        void Play();
        bool keepPlaying(int);
};

#endif
