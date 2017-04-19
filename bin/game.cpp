#include "game.h"
//#include "ScoreCard.h"
#include <sstream>
#include <cctype> //For isDigit()
#include <stdlib.h>

using namespace std;

game::game(){

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
        if(newChoice >=1 && newChoice <=13)
        {
            validChoice = true;
        }
        
        if(!validChoice)
        {
            cout << "Sorry. Not a valid choice. ";
            cout << "Please enter a different category number: ";
            cin >> choice;
            newChoice = atoi(choice.c_str());
        }
    }
    
    return intChoice;
}
