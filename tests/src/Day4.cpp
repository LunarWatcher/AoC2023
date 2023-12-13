#include "aoc/days/Day4.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day4]") {
    REQUIRE(
        aoc::Day4("inputs/test/d4p1.txt")
            .part1() == 13
    );
}

TEST_CASE("Part 2", "[Day4]") {
    REQUIRE(
        aoc::Day4("inputs/test/d4p1.txt")
            .part2() == 30
    );
}
