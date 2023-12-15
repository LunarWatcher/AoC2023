#include "aoc/days/Day5.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day5]") {
    REQUIRE(
        aoc::Day5("inputs/test/d5p1.txt")
            .part1() == 35
    );
}
TEST_CASE("Part 2", "[Day5]") {
    REQUIRE(
        aoc::Day5("inputs/test/d5p1-2.txt")
            .part2() == 0
    );
    REQUIRE(
        aoc::Day5("inputs/test/d5p1.txt")
            .part2() == 46
    );
}
