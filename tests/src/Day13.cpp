#include "aoc/days/Day13.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day13]") {
    REQUIRE(aoc::Day13("inputs/test/d13.txt").part1() == 405);
}

TEST_CASE("Part 1 - Edge cases (1)", "[Day13]") {
    REQUIRE(aoc::Day13("inputs/test/d13-2.txt").part1() == 709);
}

TEST_CASE("Part 1 - Edge cases (2)", "[Day13]") {
    REQUIRE(aoc::Day13("inputs/test/d13-3.txt").part1() == 1600);
}

TEST_CASE("Part 1 - Edge cases (3)", "[Day13]") {
    REQUIRE(aoc::Day13("inputs/test/d13-4.txt").part1() == 1);
}
