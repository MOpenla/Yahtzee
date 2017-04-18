#include "catch.hpp"
#include "game.cpp"
#include "die.h"
#include <stdexcept>

TEST_CASE( “Game class", “[game]” ) {
    game game;
    int numberOfUnplayedCategories = 12;

    SECTION(“Game keeps playing if number of unplayed categories is greater than 0“) {
        REQUIRE(keepPlaying(numberOfUnplayedCategories));
    }
    numberOfUnplayedCategories = 0;
    SECTION(“Game stops playing once number of un-played categories is 0”) {
	REQUIRE(!keepPlaying(numberOfUnplayedCategories));
    }
}

