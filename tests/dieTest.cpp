#include "catch.hpp"
#include "die.h"
#include <stdexcept>

TEST_CASE( "Die class", "[die]" ) {
    die d;

    SECTION("Get Value") {
        REQUIRE( (d.getValue() > 0 && d.getValue() < 7) );
    }

    SECTION("getValue() is random") {
        REQUIRE( d.getValue() != d.getValue() );
    }
}