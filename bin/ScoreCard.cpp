//
//  ScoreCard.cpp
//  Assignment 6    CS 3540
//
//  Created by Zaren Wienclaw on 4/17/17.
//  Copyright © 2017 Zaren Wienclaw. All rights reserved.
//

#include "ScoreCard.h"

//Constructor
ScoreCard::ScoreCard()
{
    cat[0] = "Ace";
    cat[1] = "Twos";
    cat[2] = "Threes";
    cat[3] = "Fours";
    cat[4] = "Fives";
    cat[5] = "Sixes";
    cat[6] = "TOAK";
    cat[7] = "FOAK";
    cat[8] = "Full";
    cat[9] = "Small";
    cat[10] = "Large";
    cat[11] = "Yahtzee";
    cat[12] = "Chance";
    
    unplayed.push_back("Ace");
    unplayed.push_back("Twos");
    unplayed.push_back("Threes");
    unplayed.push_back("Fours");
    unplayed.push_back("Fives");
    unplayed.push_back("Sixes");
    unplayed.push_back("TOAK");
    unplayed.push_back("FOAK");
    unplayed.push_back("Full");
    unplayed.push_back("Small");
    unplayed.push_back("Large");
    unplayed.push_back("Yahtzee");
    unplayed.push_back("Chance");
    
    for (int i=0; i<13; i++)
    {
        scores[i] = 0;
    }
    Total = 0;
    
    
}


int sumDiceOfValue(Dice d, int val)
{
    int sum = 0;
    
    for (int i = 1; i <= 5; i++) {
        if (d[i] == val) {
            sum += d[i];
        }
    }
    
    return sum;
}

int ScoreCard::getAce(Dice dice)
{
    return sumDiceOfValue(dice, 1);
}

void ScoreCard::setAce(Dice die)
{
    scores[0] = this->getAce(die);
    unplayed.remove("Ace");
    played.push_back("Ace");
    this->setTotalScore(scores[0]);
}
int ScoreCard::getTwo(Dice dice)
{
    return sumDiceOfValue(dice, 2);
}


void ScoreCard::setTwo(Dice die)
{
    scores[1] = this->getTwo(die);
    unplayed.remove("Twos");
    played.push_back("Twos");
    this->setTotalScore(scores[1]);
}

int ScoreCard::getThree(Dice dice)
{
    return sumDiceOfValue(dice, 3);
}

void ScoreCard::setThree(Dice die)
{
    scores[2] = this->getThree(die);
    unplayed.remove("Threes");
    played.push_back("Threes");
    this->setTotalScore(scores[2]);
}

int ScoreCard::getFour(Dice dice)
{
    return sumDiceOfValue(dice, 4);
}

void ScoreCard::setFour(Dice die)
{
    scores[3] = this->getFour(die);
    unplayed.remove("Fours");
    played.push_back("Fours");
    this->setTotalScore(scores[3]);
}
int ScoreCard::getFive(Dice diceFi)
{
    return sumDiceOfValue(diceFi, 5);
}

void ScoreCard::setFive(Dice die)
{
    scores[4] = this->getFive(die);
    unplayed.remove("Fives");
    played.push_back("Fives");
    this->setTotalScore(scores[4]);
}

int ScoreCard::getSix(Dice diceS)
{
    return sumDiceOfValue(diceS, 6);
}

void ScoreCard::setSix(Dice die)
{
    scores[5] = this->getSix(die);
    unplayed.remove("Sixes");
    played.push_back("Sixes");
    this->setTotalScore(scores[5]);
}

int ScoreCard::getTOAK(Dice diceTo){
    vector<int> values = diceTo.getValues();
    bool isTOAK = false;
    int sum = 0;
    
    for(int i = 0; i <values.size() && !isTOAK; i++) {
        int sameDie = 0;
        for(int j = 0; j < values.size() && !isTOAK; j++){
            if(values[i] == values[j]){
                sameDie++;
            }
            isTOAK = sameDie == 3;
        }
    }
    
    if(isTOAK) {
        sum = diceTo.sum();
    }
    
    return sum;
}
void ScoreCard::setTOAK(Dice die)
{
    scores[6] = this->getTOAK(die);
    unplayed.remove("TOAK");
    played.push_back("TOAK");
    this->setTotalScore(scores[6]);
}


int ScoreCard::getFOAK(Dice diceFo){
    vector<int> values = diceFo.getValues();
    bool isFOAK = false;
    int sum = 0;
    
    for(int i = 0; i < values.size() && !isFOAK; i++){
        int sameDie = 0;
        for(int j = 0; j < values.size() && !isFOAK; j++){
            if(values[i] == values[j]){
                sameDie++;
            }
            isFOAK = sameDie == 4;
        }
    }
    
    if(isFOAK){
        sum = diceFo.sum();
    }
    
    return sum;
}

void ScoreCard::setFOAK(Dice die){
    scores[7] = this->getFOAK(die);
    unplayed.remove("FOAK");
    played.push_back("FOAK");
    this->setTotalScore(scores[7]);
}
int ScoreCard::getFull(Dice dice) {
    int sum = 0;
    int valFreq[7] = {-1, 0, 0, 0, 0, 0, 0};
    bool foundStraight = false;
    
    //Iterate through the dice and find the frequency of each value
    for (int i = 1; i <= 5; i++) {
        valFreq[dice[i]]++;
    }
    
    //Interate through the frequencies
    for (int i = 1; i < 7 && !foundStraight; i++) {
        //If one of the dice's frequency is 3...
        if (valFreq[i] == 3) {
            //Check the frequencies for a 2
            for (int j = 1; j < 7 && !foundStraight;  j++) {
                if (valFreq[j] == 2) {
                    foundStraight = true;
                    sum = 25;
                }
            }
        }
    }
    
    return sum;
}

void ScoreCard::setFull(Dice die) {
    scores[8] = this->getFull(die);
    unplayed.remove("Full");
    played.push_back("Full");
    this->setTotalScore(scores[8]);
    
}
int ScoreCard::getSmall(Dice diceSm) {
    vector<int> values = diceSm.getValues();
    int startO = 1;
    int startT = 2;
    int startTh = 3;
    int sum = 0;
    bool isStraight = false;
    
    for (int i = 0; i < values.size() && !isStraight; i++) {
        for(int j = 0; j < values.size() && !isStraight; j++) {
            if(startO == values[j]) {
                startO++;
            }
        }
        
        for(int k = 0; k < values.size() && !isStraight; k++) {
            if(startT == values[k]) {
                startT++;
            }
        }
        
        for(int l = 0; l < values.size() && !isStraight; l++) {
            if(startTh == values[l]) {
                startTh++;
            }
        }
        
        if(startO >= 4 || startT >= 5 || startTh >= 6) {
            isStraight = true;
        }
    }
    
    
    if(isStraight) {
        sum = 30;
    }
    
    return sum;
    
}

void ScoreCard::setSmall(Dice die)
{
    scores[9] = this->getSmall(die);
    unplayed.remove("Small");
    played.push_back("Small");
    this->setTotalScore(scores[9]);
}
int ScoreCard::getLarge(Dice diceL) {
    vector<int> values = diceL.getValues();
    int startO = 1;
    int startT = 2;
    bool isStraight = false;
    int sum = 0;
    
    for (int i = 0; i < values.size() && !isStraight; i++) {
        for(int j = 0; j < values.size() && !isStraight; j++) {
            if(startO == values[j]) {
                startO++;
            }
        }
        
        for(int k = 0; k < values.size() && !isStraight; k++) {
            if(startT == values[k]) {
                startT++;
            }
        }
        
        if(startO >= 5 || startT >= 6) {
            isStraight = true;
        }
    }
    
    if(isStraight) {
        sum = 40;
    }
    
    return sum;
}

void ScoreCard::setLarge(Dice die)
{
    scores[10] = this->getLarge(die);
    unplayed.remove("Large");
    played.push_back("Large");
    this->setTotalScore(scores[10]);
}

int ScoreCard::getYahtzee(Dice diceY)
{
    int sum = 0;
    if (diceY.getValue(1) == diceY.getValue(2) && diceY.getValue(1) == diceY.getValue(3) && diceY.getValue(1) == diceY.getValue(4) && diceY.getValue(1) == diceY.getValue(5))
    {
        sum = 50;
    }
    return sum;
}

void ScoreCard::setYahtzee(Dice die)
{
    scores[11] = this->getYahtzee(die);
    unplayed.remove("Yahtzee");
    played.push_back("Yahtzee");
    this->setTotalScore(scores[11]);
}
int ScoreCard::getChance(Dice diceC) {
    return diceC.sum();
}

void ScoreCard::setChance(Dice die)
{
    scores[12] = this->getChance(die);
    unplayed.remove("Chance");
    played.push_back("Chance");
    this->setTotalScore(scores[12]);
}

int ScoreCard::getTotalScore() {
    int t = Total,
    uppersection = 0;
    
    //Check if upper section bonus gets applied
    for (int i = 0; i < 6; i++) {
        uppersection += scores[i];
    }
    
    if (uppersection >= 63) {
        t += 35;
    }
    
    return t;
}

void ScoreCard::setTotalScore(int num) {
    Total += num;
}
vector<string> ScoreCard::unplayedCategories() {
    vector<string> temp;
    
    for (list<string>::iterator it = unplayed.begin(); it != unplayed.end(); ++it) {
        temp.push_back(*it);
    }
    
    return temp;
}

vector<string> ScoreCard::playedCategories() {
    vector<string> temp;
    
    for (list<string>::iterator it = played.begin(); it != played.end(); ++it) {
        temp.push_back(*it);
    }
    
    return temp;
    
}


int ScoreCard::numberOfUnplayedCategories() {
    return unplayed.size();
}



