#pragma once

#include "aoc/days/Day.hpp"
#include <unordered_map>
#include <vector>

namespace aoc {

class Day8 : public Day {
private:
    struct Node {
        std::string ident;
        std::string left, right;
    };

    enum class Direction { LEFT, RIGHT };

    std::unordered_map<std::string, Node> nodes;
    std::vector<Direction> instructions;

public:
    Day8(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
