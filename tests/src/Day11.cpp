#include "aoc/days/Day11.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day11]") {
    REQUIRE(aoc::Day11("inputs/test/d11.txt").part1() == 374);
}

TEST_CASE("Expansion logic", "[Day11]") {
    auto d = aoc::Day11("inputs/test/d11.txt");
    REQUIRE(
        d.transform({
            {4, 0}
        }, 2)
        .at(0)
        == std::pair<long long, long long>{5, 0}
    );
}
