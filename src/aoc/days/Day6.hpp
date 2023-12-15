#pragma once

#include "aoc/days/Day.hpp"
#include <vector>
namespace aoc {

class Day6 : public Day {
private:
    struct Race {
        long long time;
        long long recordDistance;
    };
    std::vector<Race> races;
    Race p2Race;

    long long countWinWays(const Race& race);

public:
    Day6(const std::string& input);

    long long part1() override;
    long long part2() override;

};

}
