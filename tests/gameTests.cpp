#include "catch.hpp"
#include "Game.h"
#include "Game.cpp"
//#include "dice.h"
//#include "dice.cpp"
//#include "scorecard.h"
//#include "scorecard.cpp"
#include <string>
#include <stdexcept>
#include <vector>

TEST_CASE( "keepPlaying function of game class", "[game]" ) {
    Game game;
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
    Game game;
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
    Game game;
    string category = "Ace";
    
    SECTION("Game correctly decides whether category is unplayed or not") {
        REQUIRE(isUnplayed(category));
    }
    
    category = "Fifteens";
    SECTION("Game correctly decides that the category has already been played") {
        REQUIRE(!isUnplayed(category));
    }
}

/*TEST_CASE( "setScore function of Game class", "[game"){
    game game;
    int catNum;
    dice dice;
    dice.roll();
    
    catNum = 1;
    
    SECTION("Game correctly sets score for each category given dice values") {
        
    }
    
}*/

