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
    SECTION("Scorecard returns valid sum for fives category" )
    {
        dice.roll();
        ScoreCard.setFive(dice);
        REQUIRE( ScoreCard.getFive(dice)%5==0);
        REQUIRE( ScoreCard.getFive(dice)<=25);
        REQUIRE( ScoreCard.getFive(dice)>=0);
    }
    SECTION("Scorecard returns valid sum for sixes category" )
    {
        dice.roll();
        ScoreCard.setSix(dice);
        REQUIRE( ScoreCard.getSix(dice)%6==0);
        REQUIRE( ScoreCard.getSix(dice)<=36);
        REQUIRE( ScoreCard.getSix(dice)>=0);
    }
    SECTION("Scorecard returns valid sum for TOAK category")
    {
        int array[6] = { -1, 1, 1, 1, 4, 5};
        dice.roll();
        testCat(dice,array);
        ScoreCard.setTOAK(dice);
        REQUIRE(ScoreCard.getTOAK(dice)==12);
    }
    SECTION("Scorecard returns 0 if not Three of a Kind")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setTOAK(dice);
        REQUIRE(ScoreCard.getTOAK(dice) == 0);
    }
    SECTION("Scorecard returns valid sum for FOAK category")
    {
        int array[6] = { -1, 1, 1, 1, 1, 5};
        dice.roll();
        testCat(dice, array);
        ScoreCard.setFOAK(dice);
        REQUIRE(ScoreCard.getFOAK(dice)==9);
    }
    SECTION("Scorecard returns 0 if not Four of a Kind")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setFOAK(dice);
        REQUIRE(ScoreCard.getFOAK(dice) == 0);
    }
    SECTION("Scorecard returns valid sum for Full House category")
    {
        int array[6] = { -1, 1, 1, 1, 5, 5};
        dice.roll();
        testCat(dice, array);
        ScoreCard.setFull(dice);
        REQUIRE(ScoreCard.getFull(dice)==25);
    }
    SECTION("Scorecard returns 0 if not Full House")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setFull(dice);
        REQUIRE(ScoreCard.getFull(dice) == 0);
    }
    SECTION("Scorecard returns valid sum for Small Straight category")
    {
        int array[6] = { -1, 1, 2, 3, 4, 6};
        dice.roll();
        testCat(dice, array);
        ScoreCard.setSmall(dice);
        REQUIRE(ScoreCard.getSmall(dice)==30);
    }
    SECTION("Scorecard returns 0 if not Small Straight")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setSmall(dice);
        REQUIRE(ScoreCard.getSmall(dice) == 0);
    }
    SECTION("Scorecard returns valid sum for Large Straight category")
    {
        int array[6] = { -1, 1, 2, 3, 4, 5};
        dice.roll();
        testCat(dice, array);
        ScoreCard.setLarge(dice);
        REQUIRE(ScoreCard.getLarge(dice)==40);
    }
    SECTION("Scorecard returns 0 if not Large Straight")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setLarge(dice);
        REQUIRE(ScoreCard.getLarge(dice) == 0);
    }
    SECTION("Scorecard returns valid sum for Yahtzee category")
    {
        int array[6] = { -1, 1, 1, 1, 1, 1};
        dice.roll();
        testCat(dice, array);
        ScoreCard.setYahtzee(dice);
        REQUIRE(ScoreCard.getYahtzee(dice)==49);
    }
    SECTION("Scorecard returns 0 if not Yahtzee")
    {
        int array[6] = { -1, 1, 1, 6, 4, 5};
        testCat(dice, array);
        ScoreCard.setYahtzee(dice);
        REQUIRE(ScoreCard.getYahtzee(dice) == 1);
    }




}
