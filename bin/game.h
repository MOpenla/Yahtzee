#ifndef GAME_H
#define GAME_H

#include "Dice.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Game{
    private:
        void Display(int []);
        
    public:
        Game();
        void Play();
        bool keepPlaying(int);
};

#endif