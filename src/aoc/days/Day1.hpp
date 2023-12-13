#pragma once

#include "Day.hpp"
#include <vector>

namespace aoc {

class Day1 : public Day {
private:
    std::vector<std::string> raw;

public:
    Day1(const std::string& input);

    long long part1() override;
    long long part2() override;

};

}
