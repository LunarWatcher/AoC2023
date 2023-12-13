#include "aoc/days/Day1.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day1]") {
    REQUIRE(
        aoc::Day1("inputs/test/d1p1-1.txt").part1() == 142
    );
}
TEST_CASE("Part 2", "[Day1]") {
    REQUIRE(
        aoc::Day1("inputs/test/d1p2-1.txt").part2() == 281
    );
}
