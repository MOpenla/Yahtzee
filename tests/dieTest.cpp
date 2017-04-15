#include "catch.hpp"
#include "die.h"
#include <stdexcept>

TEST_CASE( "Die class", "[die]" ) {
    die d;

    SECTION("Get Value") {
        d.roll();

        REQUIRE( (d.getValue() > 0 && d.getValue() < 7) );
    }

    SECTION("getValue() is random") {
        die d2;

        d.roll();
        d2.roll();

        REQUIRE( d.getValue() != d2.getValue() );
    }

    SECTION("die is 0 before rolled") {
        REQUIRE( d.getValue() == 0 );
    }
}