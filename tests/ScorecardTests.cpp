//
//  ScorecardTests.cpp
//  Assignment 6    CS 3540
//
//  Created by Zaren Wienclaw on 4/17/17.
//  Copyright © 2017 Zaren Wienclaw. All rights reserved.
//

#include "catch.hpp"
#include "ScoreCard.h"
#include <stdexcept>
#include <vector>



void testCat(Dice &die, int array[])
{
    for(int k = 1; k<6;k++)
    {
        while(array[k] != die.getValue(k))
        {
            die.reroll(k);
        }
    }
}

TEST_CASE("Scorecard Test Implementation", "[ScoreCard]")
{
    ScoreCard ScoreCard;
    Dice dice;
    
    SECTION("Scorecard returns valid sum for aces category" )
    {
        dice.roll();
        ScoreCard.setAce(dice);
        REQUIRE( ScoreCard.getAce(dice)<=5);
        REQUIRE( ScoreCard.getAce(dice)>=0);
    }
    SECTION ("Scorecard returns valid sum for twos category" )
    {
        dice.roll();
        ScoreCard.setTwo(dice);
        REQUIRE( ScoreCard.getTwo(dice)%2==0);
        REQUIRE( ScoreCard.getTwo(dice)<=10);
        REQUIRE( ScoreCard.getTwo(dice)>=0);
    }
    SECTION("Scorecard returns valid sum for threes category" )
    {
        dice.roll();
        ScoreCard.setThree(dice);
        REQUIRE( ScoreCard.getThree(dice)%3==0);
        REQUIRE( ScoreCard.getThree(dice)<=15);
        REQUIRE( ScoreCard.getThree(dice)>=0);
    }
    SECTION("Scorecard returns valid sum for fours category" )
    {
        dice.roll();
        ScoreCard.setFour(dice);
        REQUIRE( ScoreCard.getFour(dice)%4==0);
        REQUIRE( ScoreCard.getFour(dice)<=20);
        REQUIRE( ScoreCard.getFour(dice)>=0);
    }


}
