#include "aoc/days/Day3.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day3]") {
    REQUIRE(
        aoc::Day3("inputs/test/d3p1-1.txt")
        .part1() == 4361ll
    );
    REQUIRE(
        aoc::Day3("inputs/test/d3p1-2.txt")
        .part1() == 3606ll
    );
}
