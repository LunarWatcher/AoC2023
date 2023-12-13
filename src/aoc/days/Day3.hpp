#pragma once

#include "aoc/days/Day.hpp"

#include <map>
#include <vector>
#include <utility>

namespace aoc {

class Day3 : public Day {
private:
    struct Number {
        std::pair<long long /*y*/, long long /*x*/> start;
        long long length;
        long long value;

        std::vector<std::pair<long long, long long>> adjacentTo;
    };

    std::map<std::pair<size_t, size_t>, std::pair<char, std::vector<long long>>> chars;

    std::vector<Number> numbers;
public:
    Day3(const std::string& input);

    long long part1() override;
    long long part2() override;

};

}
