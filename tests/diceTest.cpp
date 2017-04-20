#include "catch.hpp"
#include "dice.h"
#include <stdexcept>
#include <vector>

TEST_CASE( "dice class", "[dice]" ) {
    dice d;

    SECTION("the values of unrolled dice are 0") {
        std::vector<int> vals = d.getValues();

        for(int i = 0; i < vals.size(); i++) {
            REQUIRE(vals[i] == 0);
        }
    }

    SECTION("rolled dice are between 1 and number of sides") {
        d.roll();
        std::vector<int> vals = d.getValues();

        for(int i = 0; i < vals.size(); i++) {
            REQUIRE( (vals[i] >= 1 && vals[i] <= 6) );
        }
    }

    SECTION("getValue returns a 0 before dice are rolled") {
        REQUIRE( d.getValue(1) == 0 );
    }

    SECTION("getValue returns the correct value after being rolled") {
        d.roll();

        std::vector<int> vals = d.getValues();

        for(int i = 0; i < vals.size(); i++) {
            REQUIRE( vals[i] == d.getValue(i+1) );
        }
    }

    SECTION("individual die can be rolled") {
        d.roll(1);

        REQUIRE( d.getValue(1) != 0 );

        for(int i = 2; i <= 6; i++) {
            REQUIRE(d.getValue(i) == 0);
        }
    }

    SECTION("all die can be summed") {
        d.roll();

        int sum = 0;
        for(int i = 1; i <= 6; i++) {
            sum += d.getValue(i);
        }

        REQUIRE(d.sum() == sum);
    }

    SECTION("operator[] is a alais for getValue") {
        d.roll();

        for(int i = 1; i <= 6; i++) {
            REQUIRE(d[i] == d.getValue(i));
        }
    }
}

TEST_CASE( "dice class exceptions", "[dice]" ) {
    dice d;
    d.roll();

    SECTION("roll(int) -- int must be positive") {
        REQUIRE_THROWS( d.roll(-1) );
    }

    SECTION("roll(int) -- int must be less than the number of dice") {
        REQUIRE_THROWS( d.roll(9) );
    }

    SECTION("roll(int) -- int must be less than the number of dice") {
        REQUIRE_THROWS( d.roll(7) );
    }

    SECTION("roll(int) -- int must be less than the number of dice") {
        REQUIRE_NOTHROW( d.roll(6) );
    }
}