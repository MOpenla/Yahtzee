#ifndef GAME_H
#define GAME_H

#include "dice.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Game{
    private:
        void Display(int []);
        void fillScoreArray(int[], dice);
        
    public:
        Game();
        void Play();
        bool keepPlaying(int);
        int validChoice(string);
        bool isUnplayed(string);
};

#endif
