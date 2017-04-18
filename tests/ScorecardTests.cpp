//
//  ScorecardTests.cpp
//  Assignment 6    CS 3540
//
//  Created by Zaren Wienclaw on 4/17/17.
//  Copyright © 2017 Zaren Wienclaw. All rights reserved.
//

#include "catch.hpp"
#include "ScoreCard.h"




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
    
    SECTION( "Scorecard returns valid sum for aces category" )
    {
        dice.roll();
        ScoreCard.setAce(dice);
        REQUIRE( ScoreCard.getAce(dice)<=5);
        //REQUIRE( ScoreCard.getAce(dice)>=0);
    }
/*
    SECTION("ScoreCard returns valid sum for TOAK")
    {
        int array[6] = { -1, 1, 1, 1, 4, 5};
        dice.roll();
        testCat(dice,array);
        ScoreCard.setTOAK(dice);
        REQUIRE(ScoreCard.getTOAK(dice)==12);
    }*/
}
