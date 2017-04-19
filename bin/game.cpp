#include "game.h"
//#include "ScoreCard.h"
#include <sstream>
#include <cctype> //For isDigit()
#include <stdlib.h>

using namespace std;

//ScoreCard ScoreCard;

//Function Prototypes
//void reRollDice(Dice&);
//void fillScoreArray(int[], Dice);
//bool isUnplayed(string);
//void setScore(int, Dice);

game::game(){

}

void game::Play(){
    //Dice dice;
    int currentRound = 1;
    int scoreArray[13];
    bool played[13];
    string choice;
    int diceRolls;
    string rrInput;
    int intChoice;
    
    while(keepPlaying(currentRound)) //while(keepPlaying(ScoreCard.numberOfUnplayedCategories()))
    {
        cout << "-------------------- Round " << currentRound
        << " --------------------" << endl;
        
        cout << endl << "Rolling the dice." << endl;
        //dice.roll();
        diceRolls = 1;
        
        cout << "Which category number would you like to play? ";
        cin >> choice;
        intChoice = validChoice(choice);
        
        while(played[intChoice-1])
        {
            cout <<"Sorry, that category has already been played. Please enter another category number: ";
            cin >> choice;
            intChoice = validChoice(choice);
        }
        
        played[intChoice-1] = true;
        
        //setScore(catNum, dice);
    }
    
    /*cout << endl;
    cout << "**************************************************" << endl;
    cout << "*            Round " << currentRound << " Scored ";
    cout << scoreArray[intChoice-1] << " points            *" << endl;
    cout << "**************************************************" << endl << endl;*/
    
    currentRound++;
}

void Display(int numberOfUnplayedCategories[])
{

}

bool keepPlaying(int numberOfUnplayedCategories)
{
    return numberOfUnplayedCategories>0;
}

int validChoice(string choice)
{
    int intChoice = atoi(choice.c_str());
    bool validChoice = false;
    while(!validChoice)
    {
        if(intChoice >=1 && intChoice <=13)
        {
            validChoice = true;
        }
        
        if(!validChoice)
        {
            cout << "Sorry. Not a valid choice. ";
            cout << "Please enter a different category number: ";
            cin >> choice;
            intChoice = atoi(choice.c_str());
        }
    }
    
    return intChoice;
}
