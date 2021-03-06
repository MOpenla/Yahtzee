#include "game.h"
#include "ScoreCard.h"
#include "dice.h"
#include <sstream>
#include <cctype> //For isDigit()
#include <stdlib.h>
#include <vector>

using namespace std;

ScoreCard ScoreCard;

//Function Prototypes
void setScore(int, dice);
void displayCurrentRoundScore(int, int[], int);

Game::Game(){

}

void Game::Play(){
    dice dice;
    int currentRound = 1;
    int scoreArray[13];
    bool played[13]={false};
    string choice;
    //int diceRolls;
    int intChoice;
    
    //Keep looping until all of the categories have been played
    while(keepPlaying(ScoreCard.numberOfUnplayedCategories()))
    {
        cout << "-------------------- Round " << currentRound
        << " --------------------" << endl;
        
        cout << endl << "Rolling the dice." << endl;
        dice.roll();
            
        cout << "Die results: ";
            
        //Print dice results
        for (int i = 1; i <= 5; i++) {
            cout << dice[i] << " ";
        }
        cout << endl << endl;
        
        //Fill score array with scores of unplayed categories and display them
        fillScoreArray(scoreArray, dice);
        Display(scoreArray);
            
        cout << endl << endl;
        
        cout << "Which category number would you like to play? ";
        cin >> choice;
        intChoice = validChoice(choice);
        
        //Keep looping until a valid category has been selected
        while(played[intChoice-1])
        {
            cout <<"Sorry, that category has already been played. Please enter another category number: ";
            cin >> choice;
            intChoice = validChoice(choice);
        }
        
        played[intChoice-1] = true;
        
        setScore(intChoice, dice);
        
        //Display points for current round
        displayCurrentRoundScore(currentRound, scoreArray, intChoice);
    
        currentRound++;
    }
    
    cout << endl << endl << "Your final score is: " << ScoreCard.getTotalScore() << endl << endl;
}

//This function displays all of the category scores
void Game::Display(int scoreArray[]){
    cout << "----- Upper Section -----" << endl;
    if(isUnplayed("Ace"))     {cout << "(1)  Aces............." << scoreArray[0] << endl;}
    if(isUnplayed("Twos"))    {cout << "(2)  Twos............." << scoreArray[1] << endl;}
    if(isUnplayed("Threes"))  {cout << "(3)  Threes..........." << scoreArray[2] << endl;}
    if(isUnplayed("Fours"))   {cout << "(4)  Fours............" << scoreArray[3] << endl;}
    if(isUnplayed("Fives"))	  {cout << "(5)  Fives............" << scoreArray[4] << endl;}
    if(isUnplayed("Sixes"))   {cout << "(6)  Sixes............" << scoreArray[5] << endl;}
    cout << endl << "----- Lower Section -----" << endl;
    if(isUnplayed("TOAK"))	  {cout << "(7)  Three of a Kind.." << scoreArray[6] << endl;}
    if(isUnplayed("FOAK"))	  {cout << "(8)  Four of a Kind..." << scoreArray[7] << endl;}
    if(isUnplayed("Full")) 	  {cout << "(9)  Full House......." << scoreArray[8] << endl;}
    if(isUnplayed("Small"))   {cout << "(10) Small Straight..." << scoreArray[9] << endl;}
    if(isUnplayed("Large"))	  {cout << "(11) Large Straight..." << scoreArray[10] << endl;}
    if(isUnplayed("Yahtzee")) {cout << "(12) Yahtzee.........." << scoreArray[11] << endl;}
    if(isUnplayed("Chance"))  {cout << "(13) Chance..........." << scoreArray[12] << endl;}
}

//This function determines whether the game should keep playing
bool Game::keepPlaying(int numberOfUnplayedCategories)
{
    return numberOfUnplayedCategories>0;
}

//This function determines whether the user has inputted a valid category choice
int Game::validChoice(string choice)
{
    int intDecision = atoi(choice.c_str());
    bool validDecision = false;
    while(!validDecision)
    {
        if(intDecision >=1 && intDecision <=13)
        {
            validDecision = true;
        }
        
        if(!validDecision)
        {
            cout << "Sorry. Not a valid choice. ";
            cout << "Please enter a different category number: ";
            cin >> choice;
            intDecision = atoi(choice.c_str());
        }
    }
    
    return intDecision;
}

//This function determines whether a category has been played
bool Game::isUnplayed(string category) {
    vector<string> temp = ScoreCard.unplayedCategories();
    bool notPlayed = false;
    
    for(int i = 0; i<temp.size() && !notPlayed; i++)
    {
        if(category == temp[i])
        {
            notPlayed = true;
        }
    }
    return notPlayed;
}

//This funciton fills the score array with unplayed category scores
void Game::fillScoreArray(int scoreArray[], dice dice) {
    if(isUnplayed("Ace"))     {scoreArray[0] = ScoreCard.getAce(dice);}
    if(isUnplayed("Twos"))    {scoreArray[1] = ScoreCard.getTwo(dice);}
    if(isUnplayed("Threes"))  {scoreArray[2] = ScoreCard.getThree(dice);}
    if(isUnplayed("Fours"))   {scoreArray[3] = ScoreCard.getFour(dice);}
    if(isUnplayed("Fives"))   {scoreArray[4] = ScoreCard.getFive(dice);}
    if(isUnplayed("Sixes"))   {scoreArray[5] = ScoreCard.getSix(dice);}
    if(isUnplayed("TOAK"))    {scoreArray[6] = ScoreCard.getTOAK(dice);}
    if(isUnplayed("FOAK"))    {scoreArray[7] = ScoreCard.getFOAK(dice);}
    if(isUnplayed("Full"))    {scoreArray[8] = ScoreCard.getFull(dice);}
    if(isUnplayed("Small"))   {scoreArray[9] = ScoreCard.getSmall(dice);}
    if(isUnplayed("Large"))   {scoreArray[10] = ScoreCard.getLarge(dice);}
    if(isUnplayed("Yahtzee")) {scoreArray[11] = ScoreCard.getYahtzee(dice);}
    if(isUnplayed("Chance"))  {scoreArray[12] = ScoreCard.getChance(dice);}
}

//This function sets the score of the valid category the user selected
void setScore(int catNum, dice dice) {
    if(catNum == 1)  {ScoreCard.setAce(dice);}
    if(catNum == 2)  {ScoreCard.setTwo(dice);}
    if(catNum == 3)  {ScoreCard.setThree(dice);}
    if(catNum == 4)  {ScoreCard.setFour(dice);}
    if(catNum == 5)  {ScoreCard.setFive(dice);}
    if(catNum == 6)  {ScoreCard.setSix(dice);}
    if(catNum == 7)  {ScoreCard.setTOAK(dice);}
    if(catNum == 8)  {ScoreCard.setFOAK(dice);}
    if(catNum == 9)  {ScoreCard.setFull(dice);}
    if(catNum == 10) {ScoreCard.setSmall(dice);}
    if(catNum == 11) {ScoreCard.setLarge(dice);}
    if(catNum == 12) {ScoreCard.setYahtzee(dice);}
    if(catNum == 13) {ScoreCard.setChance(dice);}
}

void displayCurrentRoundScore(int currentRound, int scoreArray[], int intChoice)
{
    cout << endl;
    cout << "**************************************************" << endl;
    cout << "*            Round " << currentRound << " Scored ";
    cout << scoreArray[intChoice-1] << " points            *" << endl;
    cout << "**************************************************" << endl << endl;
}
