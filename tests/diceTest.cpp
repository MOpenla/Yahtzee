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
}