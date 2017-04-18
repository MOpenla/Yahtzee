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
}