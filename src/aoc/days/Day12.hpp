#pragma once

#include "aoc/days/Day.hpp"
#include <optional>
#include <vector>

namespace aoc {

class Day12 : public Day {
private:
    enum class Component {
        WORKING,
        BROKEN,
        UNKNOWN
    };

    struct Screw {
        std::vector<Component> components;
        std::vector<long long> desiredGroups;
    };

    std::vector<Screw> input;

    std::vector<Screw> recursiveSubtree(Screw root);

public:
    Day12(const std::string& input);

    long long part1() override;
    long long part2() override;
};

}
