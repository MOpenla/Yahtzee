//
//  ScoreCard.hpp
//  Assignment 6    CS 3540
//
//  Created by Zaren Wienclaw on 4/17/17.
//  Copyright © 2017 Zaren Wienclaw. All rights reserved.
//
#ifndef SCORECARD_H
#define SCORECARD_H


#include <vector>
#include <string>
#include <stdlib.h>
#include <list>
#include "dice.h"


using namespace std;

class ScoreCard {
    
private:
    string cat[13];
    int scores[13];
    list<string> played;
    list<string> unplayed;
    int Total;
    
public:
    ScoreCard();
    int getAce(dice);
    void setAce(dice);
    int getTwo(dice);
    void setTwo(dice);
    int getThree(dice);
    void setThree(dice);
    int getFour(dice);
    void setFour(dice);
    int getFive(dice);
    void setFive(dice);
    int getSix(dice);
    void setSix(dice);
    int getTOAK(dice);
    void setTOAK(dice);
    int getFOAK(dice);
    void setFOAK(dice);
    int getFull(dice);
    void setFull(dice);
    int getSmall(dice);
    void setSmall(dice);
    int getLarge(dice);
    void setLarge(dice);
    int getYahtzee(dice);
    void setYahtzee(dice);
    int getChance(dice);
    void setChance(dice);
    int getTotalScore();
    void setTotalScore(int num);
    vector<string> unplayedCategories();
    vector<string> playedCategories();
    int numberOfUnplayedCategories();
};

#endif
