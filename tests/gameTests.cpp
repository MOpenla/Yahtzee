#include "catch.hpp"
#include "game.h"
#include "game.cpp"
#include <string>
#include <stdexcept>
#include <vectors>

TEST_CASE( "keepPlaying function of game class", "[game]" ) {
    game game;
    int numberOfUnplayedCategories = 12;

    SECTION("Game keeps playing if number of unplayed categories is greater than 0") {
        REQUIRE(game.keepPlaying(numberOfUnplayedCategories));
    }
    numberOfUnplayedCategories = 0;
    SECTION("Game stops playing once number of un-played categories is 0") {
        REQUIRE(!game.keepPlaying(numberOfUnplayedCategories));
    }
}

TEST_CASE( "validChoice function of game class", "[game]" ) {
    game game;
    string choice = "1";
    
    SECTION("Game takes in a string and returns a valid choice integer") {
        REQUIRE(game.validChoice(choice)>0);
        REQUIRE(game.validChoice(choice)<14);
    }
    choice = "13";
    
    SECTION("Game takes in a string and returns a valid choice integer") {
        REQUIRE(game.validChoice(choice)>0);
        REQUIRE(game.validChoice(choice)<14);
    }
}

TEST_CASE( "isUnplayed function", "[game]") {
    game game;
    string category = "Aces";
    
    SECTION("Game correctly decides whether category is unplayed or not") {
        REQUIRE(isUnplayed(category));
    }
    
    category = "Twos";
    SECTION("Game correctly decides that the category has already been played") {
        REQUIRE(!isUnplayed(category));
    }
}

