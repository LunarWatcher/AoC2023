#include "aoc/days/Day2.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day2]") {
    REQUIRE(
        aoc::Day2("inputs/test/d2p1-1.txt").part1() == 8
    );
}

