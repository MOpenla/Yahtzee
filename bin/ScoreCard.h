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
#include "Dice.h"


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
    int getAce(Dice);
    void setAce(Dice);
    int getTwo(Dice);
    void setTwo(Dice);
    int getThree(Dice);/*
    void setThree(Dice);
    int getFour(Dice);
    void setFour(Dice);
    int getFive(Dice);
    void setFive(Dice);
    int getSix(Dice);
    void setSix(Dice);*/
    int getTOAK(Dice);
    void setTOAK(Dice);/*
    int getFOAK(Dice);
    void setFOAK(Dice);
    int getFull(Dice);
    void setFull(Dice);
    int getSmall(Dice);
    void setSmall(Dice);
    int getLarge(Dice);
    void setLarge(Dice);
    int getYahtzee(Dice);
    void setYahtzee(Dice);
    int getChance(Dice);
    void setChance(Dice);*/
    int getTotalScore();
    void setTotalScore(int num);/*
    vector<string> unplayedCategories();
    vector<string> playedCategories();
    int numberOfUnplayedCategories();*/
};

#endif
