#include "catch.hpp"
#include "die.h"
#include <stdexcept>

TEST_CASE( "Die class", "[die]" ) {
    die d;

    SECTION("Get Value is between 1 && num of sides (inclusive)") {
        d.roll();

        REQUIRE( (d.getValue() > 0 && d.getValue() < 7) );
    }

    SECTION("roll() is random") {
        die d2;

        d.roll();
        d2.roll();

        REQUIRE( d.getValue() != d2.getValue() );
    }

    SECTION("die is 0 before rolled") {
        REQUIRE( d.getValue() == 0 );
    }

    SECTION("two die can be added together") {
        die d2;
        d2.roll();

        REQUIRE( d.getValue()+d2.getValue() == d+d2);
    }

    SECTION("die can be added with an int") {
        d.roll();

        REQUIRE( d.getValue()+5 == d+5);
    }

    SECTION("two die can be checked if they are equal") {
        die d2;
        d2.roll();

        REQUIRE( (d.getValue() == d2.getValue()) == (d == d2) );
    }

    SECTION("die can be checked if it equals an int value") {
        d.roll();
        int val = 2;

        REQUIRE( (d.getValue() == val) == (d == val) );
    }
}

TEST_CASE( "Die class initializers", "[die]" ) {
    SECTION("die can be initialized with exactly 2 sides") {
        die d(2);
    }

    SECTION("two sided die returns either a 1 or a 2") {
        die d(2);

        //Roll multiple times to ensure a valid roll isn't rolled the first time
        for(int i = 0; i < 10; i++) {
            d.roll();

            REQUIRE( (d.getValue() == 1 || d.getValue() == 2) );
        }
    }

    SECTION("die can't have less than 2 sides") {
        REQUIRE_THROWS( die(1) );
    }
}