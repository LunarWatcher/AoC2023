#include "aoc/days/Day7.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Part 1", "[Day7]") {
    REQUIRE(aoc::Day7("inputs/test/d7.txt").part1() == 6440);
}
TEST_CASE("Part 2", "[Day7]") {
    REQUIRE(aoc::Day7("inputs/test/d7.txt").part2() == 5905);
}

TEST_CASE("Fuck sorting: revenge of part 2", "[Day7]") {
    auto d = aoc::Day7("inputs/test/d7.txt");
    d.part2();
    REQUIRE(d.hands.at(0).bet == 765);
    REQUIRE(d.hands.at(1).bet == 28);
    REQUIRE(d.hands.at(2).bet == 684);
    REQUIRE(d.hands.at(3).bet == 483);
    REQUIRE(d.hands.at(4).bet == 220);
}

TEST_CASE("Fuck sorting", "[Day7]") {
    auto d = aoc::Day7("inputs/test/d7.txt");
    REQUIRE(d.hands.at(0).bet == 765);
    REQUIRE(d.hands.at(1).bet == 220);
    REQUIRE(d.hands.at(2).bet == 28);
    REQUIRE(d.hands.at(3).bet == 684);
    REQUIRE(d.hands.at(4).bet == 483);
}

TEST_CASE("I fucking hate sorting", "[Day7]") {
    aoc::Day7 d("inputs/test/d7-2.txt");
    REQUIRE(d.hands.size() == 13);
    REQUIRE(d.hands.at(0).hand.at(0) == 1);
    REQUIRE(d.hands.at(1).hand.at(0) == 2);
    REQUIRE(d.hands.at(2).hand.at(0) == 3);
    REQUIRE(d.hands.at(3).hand.at(0) == 4);
    REQUIRE(d.hands.at(4).hand.at(0) == 5);
    REQUIRE(d.hands.at(5).hand.at(0) == 6);
    REQUIRE(d.hands.at(6).hand.at(0) == 7);
    REQUIRE(d.hands.at(7).hand.at(0) == 8);
    REQUIRE(d.hands.at(8).hand.at(0) == 9);
    REQUIRE(d.hands.at(9).hand.at(0) == 10);
    REQUIRE(d.hands.at(10).hand.at(0) == 11);
    REQUIRE(d.hands.at(11).hand.at(0) == 12);
    REQUIRE(d.hands.at(12).hand.at(0) == 13);
}

TEST_CASE("Why the fuck do sort functions have to be so difficult?", "[Day7]") {
    aoc::Day7 d("inputs/test/d7-3.txt");
    REQUIRE(d.hands.at(0).hand.at(0) == 1);
    REQUIRE(d.hands.at(1).hand.at(0) == 3);
    REQUIRE(d.hands.at(2).hand.at(0) == 4);
    REQUIRE(d.hands.at(3).hand.at(0) == 5);
    REQUIRE(d.hands.at(4).hand.at(0) == 6);
    REQUIRE(d.hands.at(5).hand.at(0) == 8);
    REQUIRE(d.hands.at(6).hand.at(0) == 9);
    REQUIRE(d.hands.size() == 7);
}

TEST_CASE("Fucking garbage fucking sorting", "[Day7]") {
    aoc::Day7 d("inputs/test/d7-4.txt");
    REQUIRE(d.part1() == 6592);
}

TEST_CASE("Sorting edge-case 1", "[Day7]") {
    aoc::Day7 d("inputs/test/d7-5.txt");
    for (auto& c : d.hands) {
        if (c.bet == 13) {
            REQUIRE(c.t == aoc::Type::ONE);
        } else {
            REQUIRE(c.t == aoc::Type::TWO);
        }
    }
    REQUIRE(d.hands.at(0).bet == 13);
    REQUIRE(d.hands.at(1).bet == 17);
    REQUIRE(d.part1() == 47);

}
TEST_CASE("Sorting edge-case 2", "[Day7]") {
    aoc::Day7 d("inputs/test/d7-6.txt");
    for (auto& c : d.hands) {
        if (c.bet == 31) {
            REQUIRE(c.t == aoc::Type::THREE);
        } else {
            REQUIRE(c.t == aoc::Type::FULL);
        }
    }
    REQUIRE(d.hands.at(0).bet == 31);
    REQUIRE(d.hands.at(1).bet == 19);
    REQUIRE(d.part1() == 69);

}

TEST_CASE("Fucking evil elf", "[Day7]") {

    aoc::Day7 d("inputs/test/d7-4.txt");
    auto res = d.part2();
    REQUIRE(d.hands.size() == 19);
    REQUIRE(d.hands.at(0).t == aoc::Type::HIGH);
    REQUIRE(d.hands.at(0).bet == 1);
    REQUIRE(d.hands.at(1).bet == 2);
    REQUIRE(d.hands.at(2).bet == 3);
    REQUIRE(d.hands.at(3).bet == 5);
    REQUIRE(d.hands.at(4).bet == 7);
    REQUIRE(d.hands.at(5).bet == 11);
    REQUIRE(d.hands.at(6).bet == 13);
    REQUIRE(d.hands.at(7).bet == 17);
    REQUIRE(d.hands.at(8).bet == 19);
    REQUIRE(d.hands.at(9).bet == 23);
    REQUIRE(d.hands.at(10).bet == 29);
    REQUIRE(d.hands.at(11).bet == 31);
    REQUIRE(d.hands.at(12).bet == 34);
    REQUIRE(d.hands.at(13).bet == 37);
    REQUIRE(d.hands.at(14).bet == 41);
    REQUIRE(d.hands.at(15).bet == 43);
    REQUIRE(d.hands.at(16).bet == 53);
    REQUIRE(d.hands.at(17).bet == 59);
    REQUIRE(d.hands.at(18).bet == 61);
    REQUIRE(res == 6839);
}
