#include "catch.hpp"
#include "game.cpp"
#include <string>
#include <stdexcept>

TEST_CASE( "keepPlaying function of game class", "[game]" ) {
    game game;
    int numberOfUnplayedCategories = 12;

    SECTION("Game keeps playing if number of unplayed categories is greater than 0") {
        REQUIRE(keepPlaying(numberOfUnplayedCategories));
    }
    numberOfUnplayedCategories = 0;
    SECTION("Game stops playing once number of un-played categories is 0") {
        REQUIRE(!keepPlaying(numberOfUnplayedCategories));
    }
}

TEST_CASE( "validChoice function of game class", "[game]" ) {
    game game;
    string choice = "1";
    
    SECTION("Game takes in a string and returns a valid choice integer") {
        REQUIRE(validChoice(choice)>0);
        REQUIRE(validChoice(choice)<14);
    }
    choice = "13";
    
    SECTION("Game takes in a string and returns a valid choice integer") {
        REQUIRE(validChoice(choice)>0);
        REQUIRE(validChoice(choice)<14);
    }
}

